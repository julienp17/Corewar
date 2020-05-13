/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Unit tests for op_get_by_code
*/

#include <criterion/criterion.h>
#include "corewar.h"

Test(op_get_by_code, live)
{
    unsigned char code = 0x01;
    op_t actual = (op_t) {0, 0, {0}, 0, 0, 0};
    op_t expected = (op_t) {"live", 1, {T_DIR}, 1, 10, "alive"};

    actual = op_get_by_code(code);
    cr_assert_str_eq(actual.mnemonique, expected.mnemonique);
    cr_assert_eq(actual.nbr_args, expected.nbr_args);
    for (int i = 0 ; i < expected.nbr_args ; i++)
        cr_assert_eq(actual.type[i], expected.type[i]);
    cr_assert_eq(actual.code, code);
    cr_assert_eq(actual.code, expected.code);
    cr_assert_str_eq(actual.comment, expected.comment);
}

Test(op_get_by_code, invalid_code_zero)
{
    unsigned char code = 0x00;
    op_t actual = (op_t) {0, 0, {0}, 0, 0, 0};
    op_t expected = (op_t) {0, 0, {0}, 0, 0, 0};

    actual = op_get_by_code(code);
    cr_assert_eq(actual.mnemonique, expected.mnemonique);
    cr_assert_eq(actual.nbr_args, expected.nbr_args);
    for (int i = 0 ; i < expected.nbr_args ; i++)
        cr_assert_eq(actual.type[i], expected.type[i]);
    cr_assert_eq(actual.code, code);
    cr_assert_eq(actual.code, expected.code);
    cr_assert_eq(actual.comment, expected.comment);
}