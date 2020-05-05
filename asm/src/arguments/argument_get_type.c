/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** Returns the type of the argument
*/

#include "asm.h"
#include "my.h"

int argument_get_type(char const *arg)
{
    if (arg[0] == REGISTER_CHAR)
        return (T_REG);
    if (arg[0] == DIRECT_CHAR)
        return (T_DIR);
    if (arg[0] == LABEL_CHAR)
        return (T_LAB);
    if (my_char_is_digit(arg[0]))
        return (T_IND);
    return (0);
}