/*
** EPITECH PROJECT, 2020
** Corewar Assembler
** File description:
** Encode an instruction
*/

#include <stdbool.h>
#include "asm.h"
#include "my.h"

static int write_instruction(int fd, op_t op, char **tokens);
static ssize_t write_coding_byte(int fd, char nbr_args, char **args);
static ssize_t write_param_value(int fd, op_t op, char *arg);
static bool arg_is_index(op_t op);

int encode_instruction(int fd, char const *instruction)
{
    op_t op;
    char **tokens = NULL;
    int status = 0;

    tokens = parse_instruction(instruction);
    if (tokens == NULL)
        return (EXIT_FAILURE);
    if (instruction_is_correct(tokens) == false)
        return (EXIT_FAILURE);
    if (get_argument_type(tokens[0]) == T_LAB)
        my_strarr_rotate(tokens, 0);
    op = get_op_by_name(tokens[0]);
    status = write_instruction(fd, op, tokens);
    my_free_str_array(tokens);
    return (status);
}

static int write_instruction(int fd, op_t op, char **tokens)
{
    if (write(fd, &(op.code), sizeof(op.code)) < 0) {
        my_puterr("Error writing to file.\n");
        return (EXIT_FAILURE);
    }
    if (op.nbr_args != 1 || op.type[0] != T_DIR)
        if (write_coding_byte(fd, op.nbr_args, tokens + 1) < 0)
            return (EXIT_FAILURE);
    for (int i = 1 ; tokens[i] ; i++)
        if (write_param_value(fd, op, tokens[i]) < 0)
            return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

static ssize_t write_coding_byte(int fd, char nbr_args, char **args)
{
    unsigned char coding_byte = 0;
    ssize_t write_size = 0;
    int arg_type = 0;

    for (int i = 0 ; args[i] ; i++) {
        arg_type = get_argument_type(args[i]);
        arg_type -= (arg_type == T_IND) ? 1 : 0;
        coding_byte = (coding_byte << 2) + arg_type;
    }
    for (int i = nbr_args ; i < MAX_ARGS_NUMBER ; i++)
        coding_byte <<= 2;
    write_size = write(fd, &(coding_byte), sizeof(coding_byte));
    return (write_size);
}

static ssize_t write_param_value(int fd, op_t op, char *arg)
{
    ssize_t write_size = 0;
    int arg_type = 0;
    int value = 0;

    arg_type = get_argument_type(arg);
    if (arg_type == T_REG) {
        value = (char)my_atoi(arg + 1);
        write_size = write(fd, &value, 1);
    } else if (arg_type == T_IND) {
        value = (short int)my_atoi(arg);
        value = (short int)swap_int16(value);
        write_size = write(fd, &value, IND_SIZE);
    } else if (arg_type == T_DIR) {
        if (arg_is_index(op))
            return (write_param_value(fd, op, arg + 1));
        value = my_atoi(arg + 1);
        value = swap_int32(value);
        write_size = write(fd, &(value), DIR_SIZE);
    }
    return (write_size);
}

static bool arg_is_index(op_t op)
{
    return (
        my_str_contains(op.comment, "index")
        || (op.nbr_args == 1 && op.type[0] == T_DIR
            && my_strcmp(op.mnemonique, "live") != 0)
    );
}