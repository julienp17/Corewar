/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** Returns the size of an argument
*/

#include "argument.h"

char argument_get_size(char const arg_type, op_t op)
{
    if (arg_type == T_REG)
        return (1);
    if (arg_type == T_IND)
        return (IND_SIZE);
    if (arg_type == T_DIR)
        return (argument_is_index(op) ? IND_SIZE : DIR_SIZE);
    return (-1);
}