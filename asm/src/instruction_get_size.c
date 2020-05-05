/*
** EPITECH PROJECT, 2020
** asm
** File description:
** instruction_get_size
*/

#include "asm.h"

int16_t instruction_get_size(char const *instruction)
{
    char **tokens = NULL;
    op_t op;
    int16_t offset = 0;
    int arg_size = 0;
    int total_args_size = 0;

    tokens = parse_instruction(instruction);
    if (my_str_ends_char(tokens[0], LABEL_CHAR))
        my_strarr_rotate(tokens, 0);
    if (tokens[0] == NULL)
        return (0);
    op = get_op_by_name(tokens[0]);
    if (op.mnemonique == 0)
        return (-1);
    offset += sizeof(char);
    offset += (op.nbr_args != 1 || op.type[0] != T_DIR);
    for (int i = 1 ; tokens[i] ; i++) {
        arg_size = get_argument_size(op, tokens[i]);
        total_args_size += arg_size;
    }
    offset += total_args_size;
    return (offset);
}