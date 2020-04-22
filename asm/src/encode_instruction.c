/*
** EPITECH PROJECT, 2020
** Corewar Assembler
** File description:
** Encode an instruction
*/

#include "asm.h"
#include "my.h"

static int write_instruction(int fd, op_t op, char **tokens);
static ssize_t write_param_value(int fd, char *arg);
static ssize_t write_coding_byte(int fd, char nbr_args, char **args);

int encode_instruction(int fd, char const *instruction)
{
    op_t op;
    char **tokens = NULL;
    int status = 0;

    tokens = parse_instruction(instruction);
    if (tokens == NULL)
        return (EXIT_FAILURE);
    op = get_op_by_name(tokens[0]);
    if (op.mnemonique == 0) {
        my_puterr(tokens[0]);
        my_puterr(" : Invalid instruction.\n");
        return (EXIT_FAILURE);
    }
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
    if ((op.nbr_args != 1 || op.type[0] != T_DIR))
        if (write_coding_byte(fd, op.nbr_args, tokens + 1) < 0)
            return (EXIT_FAILURE);
    for (int i = 1 ; tokens[i] ; i++)
        if (write_param_value(fd, tokens[i]) < 0)
            return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

static ssize_t write_coding_byte(int fd, char nbr_args, char **args)
{
    unsigned char coding_byte = 0;
    ssize_t write_size = 0;

    for (int i = 0 ; args[i] ; i++) {
        if (args[i][0] == REGISTER_CHAR)
            coding_byte = (coding_byte << 2) + T_REG;
        else if (args[i][0] == DIRECT_CHAR)
            coding_byte = (coding_byte << 2) + T_DIR;
        else if (my_char_is_num(args[i][0]))
            coding_byte = (coding_byte << 2) + T_IND;
    }
    for (int i = nbr_args ; i < MAX_ARGS_NUMBER ; i++)
        coding_byte <<= 2;
    write_size = write(fd, &(coding_byte), sizeof(coding_byte));
    return (write_size);
}

static ssize_t write_param_value(int fd, char *arg)
{
    param_value_t param_value;
    ssize_t write_size = 0;

    if (arg[0] == REGISTER_CHAR) {
        param_value.reg = my_atoi(arg + 1);
        write_size = write(fd, &(param_value.reg), 1);
    } else if (my_char_is_num(arg[0])) {
        param_value.indirect = my_atoi(arg);
        param_value.indirect = swap_int16(param_value.indirect);
        write_size = write(fd, &(param_value.indirect), IND_SIZE);
    } else if (arg[0] == DIRECT_CHAR) {
        param_value.direct = my_atoi(arg + 1);
        param_value.direct = swap_int32(param_value.direct);
        write_size = write(fd, &(param_value.direct), DIR_SIZE);
    }
    return (write_size);
}