/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Unit tests for argument_get_size
*/

#include <criterion/criterion.h>
#include "argument.h"
#include "corewar.h"

Test(argument_get_size, reg)
{
    char size = 0;
    char expected = 1;
    int arg_type = T_REG;
    op_t op;

    op.mnemonique = "aff";
    op = op_get_by_code(15);
    size = argument_get_size(arg_type, op);
    cr_assert_eq(size, expected);
}

Test(argument_get_size, indirect)
{
    char size = 0;
    char expected = IND_SIZE;
    int arg_type = T_IND;
    op_t op;

    op.mnemonique = "ld";
    op = op_get_by_code(2);
    size = argument_get_size(arg_type, op);
    cr_assert_eq(size, expected);
}

Test(argument_get_size, direct_as_value)
{
    char size = 0;
    char expected = DIR_SIZE;
    int arg_type = T_DIR;
    op_t op;

    op.mnemonique = "live";
    op = op_get_by_code(1);
    size = argument_get_size(arg_type, op);
    cr_assert_eq(size, expected);
}

Test(argument_get_size, direct_as_index)
{
    char size = 0;
    char expected = IND_SIZE;
    int arg_type = T_DIR;
    op_t op;

    op.mnemonique = "sti";
    op = op_get_by_code(11);
    size = argument_get_size(arg_type, op);
    cr_assert_eq(size, expected);
}

Test(argument_get_size, invalid_arg_type)
{
    char size = 0;
    char expected = 0;
    int arg_type = 99;
    op_t op;

    op.mnemonique = "aff";
    op = op_get_by_code(15);
    size = argument_get_size(arg_type, op);
    cr_assert_eq(size, expected);
}
