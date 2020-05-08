/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** Unit tests for argument_get_size
*/

#include <criterion/criterion.h>
#include "asm.h"

Test(argument_get_size, valid_register)
{
    char const *arg = "r13";
    char const op_mnemonique[] = "add";
    int const expected_size = 1;
    int argument_size = 0;
    op_t op;

    op = op_get_by_name(op_mnemonique);
    argument_size = argument_get_size(arg, op);
    cr_assert_eq(argument_size, expected_size);
}

Test(argument_get_size, indirect_value)
{
    char const *arg = "13";
    char const op_mnemonique[] = "st";
    int const expected_size = IND_SIZE;
    int argument_size = 0;
    op_t op;

    op = op_get_by_name(op_mnemonique);
    argument_size = argument_get_size(arg, op);
    cr_assert_eq(argument_size, expected_size);
}

Test(argument_get_size, indirect_label)
{
    char const *arg = ":hi";
    char const op_mnemonique[] = "sti";
    int const expected_size = IND_SIZE;
    int argument_size = 0;
    op_t op;

    op = op_get_by_name(op_mnemonique);
    argument_size = argument_get_size(arg, op);
    cr_assert_eq(argument_size, expected_size);
}

Test(argument_get_size, direct_value)
{
    char const *arg = "%34";
    char const op_mnemonique[] = "ld";
    int const expected_size = DIR_SIZE;
    int argument_size = 0;
    op_t op;

    op = op_get_by_name(op_mnemonique);
    argument_size = argument_get_size(arg, op);
    cr_assert_eq(argument_size, expected_size);
}

Test(argument_get_size, direct_as_index)
{
    char const *arg = "%:hi";
    char const op_mnemonique[] = "sti";
    int const expected_size = IND_SIZE;
    int argument_size = 0;
    op_t op;

    op = op_get_by_name(op_mnemonique);
    argument_size = argument_get_size(arg, op);
    cr_assert_eq(argument_size, expected_size);
}

Test(argument_get_size, incorrect_argument)
{
    char const *arg = "aalalalalal";
    char const op_mnemonique[] = "sti";
    int const expected_size = -1;
    int argument_size = 0;
    op_t op;

    op = op_get_by_name(op_mnemonique);
    argument_size = argument_get_size(arg, op);
    cr_assert_eq(argument_size, expected_size);
}