/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Unit tests for op_is_null
*/

#include <criterion/criterion.h>
#include "corewar.h"

Test(op_is_null, not_null)
{
    op_t op = (op_t) {"live", 1, {T_DIR}, 1, 10, "alive"};
    bool actual = false;
    bool expected = false;

    actual = op_is_null(op);
    cr_assert_eq(actual, expected);
}

Test(op_is_null, full_null)
{
    op_t op = (op_t) {0, 0, {0}, 0, 0, 0};
    bool actual = false;
    bool expected = true;

    actual = op_is_null(op);
    cr_assert_eq(actual, expected);
}

Test(op_is_null, mnemonique_not_null)
{
    op_t op = (op_t) {"live", 0, {0}, 0, 0, 0};
    bool actual = false;
    bool expected = true;

    actual = op_is_null(op);
    cr_assert_eq(actual, expected);
}

Test(op_is_null, nbr_args_not_null)
{
    op_t op = (op_t) {0, 3, {0}, 0, 0, 0};
    bool actual = false;
    bool expected = true;

    actual = op_is_null(op);
    cr_assert_eq(actual, expected);
}

Test(op_is_null, type_not_null)
{
    op_t op = (op_t) {0, 0, {T_DIR | T_REG, T_REG, T_IND}, 0, 0, 0};
    bool actual = false;
    bool expected = true;

    actual = op_is_null(op);
    cr_assert_eq(actual, expected);
}

Test(op_is_null, code_not_null)
{
    op_t op = (op_t) {0, 0, {0}, 0x04, 0, 0};
    bool actual = false;
    bool expected = true;

    actual = op_is_null(op);
    cr_assert_eq(actual, expected);
}

Test(op_is_null, nbr_cycle_not_null)
{
    op_t op = (op_t) {"live", 0, {0}, 0, 42, 0};
    bool actual = false;
    bool expected = true;

    actual = op_is_null(op);
    cr_assert_eq(actual, expected);
}

Test(op_is_null, comment_not_null)
{
    op_t op = (op_t) {0, 0, {0}, 0, 0, "just an empty op"};
    bool actual = false;
    bool expected = true;

    actual = op_is_null(op);
    cr_assert_eq(actual, expected);
}