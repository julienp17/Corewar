/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** Unit tests for argument_get_type
*/

#include <criterion/criterion.h>
#include "asm.h"

Test(argument_get_type, valid_register)
{
    char const *arg = "r13";
    int const expected_type = T_REG;
    int argument_type = 0;

    argument_type = argument_get_type(arg);
    cr_assert_eq(argument_type, expected_type);
}

Test(argument_get_type, indirect_value)
{
    char const *arg = "42";
    int const expected_type = T_IND;
    int argument_type = 0;

    argument_type = argument_get_type(arg);
    cr_assert_eq(argument_type, expected_type);
}

Test(argument_get_type, indirect_label)
{
    char const *arg = ":hi";
    int const expected_type = T_LAB;
    int argument_type = 0;

    argument_type = argument_get_type(arg);
    cr_assert_eq(argument_type, expected_type);
}

Test(argument_get_type, direct_value)
{
    char const *arg = "%34";
    int const expected_type = T_DIR;
    int argument_type = 0;

    argument_type = argument_get_type(arg);
    cr_assert_eq(argument_type, expected_type);
}

Test(argument_get_type, direct_label)
{
    char const *arg = "%:hi";
    int const expected_type = DIR_SIZE;
    int argument_type = 0;

    argument_type = argument_get_type(arg);
    cr_assert_eq(argument_type, expected_type);
}

Test(argument_get_type, incorrect_argument)
{
    char const *arg = "aalalalalal";
    int const expected_type = 0;
    int argument_type = 0;

    argument_type = argument_get_type(arg);
    cr_assert_eq(argument_type, expected_type);
}

Test(argument_get_type, incorrect_register)
{
    char const *arg = "rA";
    int const expected_type = 0;
    int argument_type = 0;

    argument_type = argument_get_type(arg);
    cr_assert_eq(argument_type, expected_type);
}

Test(argument_get_type, incorrect_direct_value)
{
    char const *arg = "%A";
    int const expected_type = 0;
    int argument_type = 0;

    argument_type = argument_get_type(arg);
    cr_assert_eq(argument_type, expected_type);
}