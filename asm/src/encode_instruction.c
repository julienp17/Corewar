/*
** EPITECH PROJECT, 2020
** Corewar Assembler
** File description:
** Encode an instruction
*/

#include <stdbool.h>
#include "asm.h"
#include "my.h"

static ssize_t write_instruction(int fd, char **tokens, label_t **labels, ssize_t current_offset);
static ssize_t write_coding_byte(int fd, char nbr_args, char **args);
static ssize_t write_param_value(int fd, op_t op, char *arg, label_t **labels, ssize_t current_offset);

ssize_t encode_instruction(int fd, char const *instruction, label_t **labels, ssize_t current_offset)
{
    char **tokens = NULL;
    ssize_t bytes_written = 0;

    if (instruction_is_correct(instruction) == false)
        return (-1);
    tokens = parse_instruction(instruction);
    if (tokens == NULL)
        return (-1);
    if (my_str_ends_char(tokens[0], LABEL_CHAR))
        my_strarr_rotate(tokens, 0);
    if (tokens[0] == NULL)
        return (0);
    bytes_written = write_instruction(fd, tokens, labels, current_offset);
    my_free_str_array(tokens);
    return (bytes_written);
}

static ssize_t write_instruction(int fd, char **tokens, label_t **labels, ssize_t current_offset)
{
    ssize_t total_bytes_written = 0;
    ssize_t bytes_written = 0;
    op_t op;

    op = get_op_by_name(tokens[0]);
    bytes_written = write(fd, &(op.code), sizeof(op.code));
    if (bytes_written < 0) {
        my_puterr("Error writing op code.\n");
        return (-1);
    }
    total_bytes_written += bytes_written;
    if (should_write_coding_byte(op)) {
        bytes_written = write_coding_byte(fd, op.nbr_args, tokens + 1);
        if (bytes_written < 0)
            return (-1);
        total_bytes_written += bytes_written;
    }
    for (int i = 1 ; tokens[i] ; i++) {
        bytes_written = write_param_value(fd, op, tokens[i], labels, current_offset);
        if (bytes_written < 0)
            return (-1);
        total_bytes_written += bytes_written;
    }
    return (total_bytes_written);
}

static ssize_t write_coding_byte(int fd, char nbr_args, char **args)
{
    unsigned char coding_byte = 0;
    ssize_t write_size = 0;
    int arg_type = 0;

    for (int i = 0 ; args[i] ; i++) {
        arg_type = get_argument_type(args[i]);
        arg_type -= (arg_type == T_IND);
        coding_byte = (coding_byte << 2) + arg_type;
    }
    for (int i = nbr_args ; i < MAX_ARGS_NUMBER ; i++)
        coding_byte <<= 2;
    write_size = write(fd, &(coding_byte), sizeof(coding_byte));
    return (write_size);
}

static ssize_t write_param_value(int fd, op_t op, char *arg, label_t **labels, ssize_t current_offset)
{
    ssize_t write_size = 0;
    int arg_type = 0;
    int value = 0;
    label_t *label = NULL;

    arg_type = get_argument_type(arg);
    if (arg_type == T_REG) {
        value = (char)my_atoi(arg + 1);
        write_size = write(fd, &value, 1);
    } else if (arg_type == T_IND || arg_type == T_LAB) {
        if (arg_type == T_IND) {
            value = (short int)my_atoi(arg);
            value = (short int)swap_int16(value);
        } else {
            my_str_rotate(arg, 0);
            for (uint i = 0 ; labels[i] && label == NULL ; i++)
                if (my_strcmp(labels[i]->name, arg) == 0)
                    label = labels[i];
            if (label == NULL) {
                my_eprintf("%s : unknown label.\n", arg);
                return (-1);
            }
            value = swap_int16(label->offset - current_offset);
        }
        write_size = write(fd, &value, IND_SIZE);
    } else if (arg_type == T_DIR) {
        if (arg_is_index(op))
            return (write_param_value(fd, op, arg + 1, labels, current_offset));
        value = my_atoi(arg + 1);
        value = swap_int32(value);
        write_size = write(fd, &(value), DIR_SIZE);
    }
    return (write_size);
}

bool arg_is_index(op_t op)
{
    return (
        my_str_contains(op.comment, "index")
        || (op.nbr_args == 1 && op.type[0] == T_DIR
            && my_strcmp(op.mnemonique, "live") != 0)
    );
}