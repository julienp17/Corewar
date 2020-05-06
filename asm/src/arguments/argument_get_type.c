/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** Returns the type of the argument
*/

#include "asm.h"
#include "my.h"

static bool is_register(char const *arg);
static bool is_direct(char const *arg);
static bool is_indirect(char const *arg);
static bool is_label(char const *arg);

int argument_get_type(char const *arg)
{
    if (is_register(arg))
        return (T_REG);
    if (is_direct(arg))
        return (T_DIR);
    if (is_indirect(arg))
        return (T_IND);
    if (is_label(arg))
        return (T_LAB);
    return (0);
}

static bool is_register(char const *arg)
{
    return (
        arg[0] == REGISTER_CHAR
        && my_str_isnum_pos(arg + 1)
    );
}

static bool is_direct(char const *arg)
{
    return (
        arg[0] == DIRECT_CHAR
        && (arg[1] == LABEL_CHAR || my_str_isnum(arg + 1))
    );
}

static bool is_indirect(char const *arg)
{
    return (my_str_isnum(arg));
}

static bool is_label(char const *arg)
{
    return (arg[0] == LABEL_CHAR);
}