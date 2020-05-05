/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** Returns the size of an argument
*/

#include "asm.h"

int argument_get_size(char const *arg, op_t op)
{
    int arg_type = 0;

    arg_type = argument_get_type(arg);
    if (arg_type == T_REG)
        return (1);
    if (arg_type == T_IND || arg_type == T_LAB)
        return (IND_SIZE);
    if (arg_type == T_DIR)
        return (argument_is_index(op) ? IND_SIZE : DIR_SIZE);
    return (-1);
}