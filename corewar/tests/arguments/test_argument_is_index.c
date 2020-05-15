/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Unit tests for argument_is_index
*/

#include <criterion/criterion.h>
#include "argument.h"
#include "corewar.h"

Test(argument_is_index, live)
{
    bool actual = false;
    bool expected = false;
    op_t op;

    op = op_get_by_code(1);
    actual = argument_is_index(op);
    cr_assert_eq(actual, expected);
}

Test(argument_is_index, ld)
{
    bool actual = false;
    bool expected = false;
    op_t op;

    op = op_get_by_code(2);
    actual = argument_is_index(op);
    cr_assert_eq(actual, expected);
}

Test(argument_is_index, st)
{
    bool actual = false;
    bool expected = false;
    op_t op;

    op = op_get_by_code(3);
    actual = argument_is_index(op);
    cr_assert_eq(actual, expected);
}

Test(argument_is_index, add)
{
    bool actual = false;
    bool expected = false;
    op_t op;

    op = op_get_by_code(4);
    actual = argument_is_index(op);
    cr_assert_eq(actual, expected);
}

Test(argument_is_index, sub)
{
    bool actual = false;
    bool expected = false;
    op_t op;

    op = op_get_by_code(5);
    actual = argument_is_index(op);
    cr_assert_eq(actual, expected);
}

Test(argument_is_index, and)
{
    bool actual = false;
    bool expected = false;
    op_t op;

    op = op_get_by_code(6);
    actual = argument_is_index(op);
    cr_assert_eq(actual, expected);
}

Test(argument_is_index, or)
{
    bool actual = false;
    bool expected = false;
    op_t op;

    op = op_get_by_code(7);
    actual = argument_is_index(op);
    cr_assert_eq(actual, expected);
}

Test(argument_is_index, xor)
{
    bool actual = false;
    bool expected = false;
    op_t op;

    op = op_get_by_code(8);
    actual = argument_is_index(op);
    cr_assert_eq(actual, expected);
}

Test(argument_is_index, zjmp)
{
    bool actual = false;
    bool expected = true;
    op_t op;

    op = op_get_by_code(9);
    actual = argument_is_index(op);
    cr_assert_eq(actual, expected);
}

Test(argument_is_index, ldi)
{
    bool actual = false;
    bool expected = true;
    op_t op;

    op = op_get_by_code(10);
    actual = argument_is_index(op);
    cr_assert_eq(actual, expected);
}

Test(argument_is_index, sti)
{
    bool actual = false;
    bool expected = true;
    op_t op;

    op = op_get_by_code(11);
    actual = argument_is_index(op);
    cr_assert_eq(actual, expected);
}

Test(argument_is_index, fork)
{
    bool actual = false;
    bool expected = true;
    op_t op;

    op = op_get_by_code(12);
    actual = argument_is_index(op);
    cr_assert_eq(actual, expected);
}

Test(argument_is_index, lld)
{
    bool actual = false;
    bool expected = false;
    op_t op;

    op = op_get_by_code(13);
    actual = argument_is_index(op);
    cr_assert_eq(actual, expected);
}

Test(argument_is_index, lldi)
{
    bool actual = false;
    bool expected = true;
    op_t op;

    op = op_get_by_code(14);
    actual = argument_is_index(op);
    cr_assert_eq(actual, expected);
}

Test(argument_is_index, lfork)
{
    bool actual = false;
    bool expected = true;
    op_t op;

    op = op_get_by_code(15);
    actual = argument_is_index(op);
    cr_assert_eq(actual, expected);
}

Test(argument_is_index, aff)
{
    bool actual = false;
    bool expected = false;
    op_t op;

    op = op_get_by_code(16);
    actual = argument_is_index(op);
    cr_assert_eq(actual, expected);
}