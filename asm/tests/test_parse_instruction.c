/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** Unit tests for parse_instruction
*/

#include <criterion/criterion.h>
#include "asm.h"

Test(parse_instruction, with_label)
{
    char const instruction[] = "hi: live %0";
    char const *expected[] = {
        "hi:", "live", "%0", NULL
    };
    char **actual = NULL;

    actual = parse_instruction(instruction);
    for (int i = 0 ; expected[i] ; i++) {
        cr_assert_str_eq(expected[i], actual[i]);
        free(actual[i]);
    }
    free(actual);
}

Test(parse_instruction, sti_without_label_1)
{
    char const instruction[] = "sti r3, %3, %:hi";
    char const *expected[] = {
        "sti", "r3", "%3", "%:hi", NULL
    };
    char **actual = NULL;

    actual = parse_instruction(instruction);
    for (int i = 0 ; expected[i] ; i++) {
        cr_assert_str_eq(expected[i], actual[i]);
        free(actual[i]);
    }
    free(actual);
}

Test(parse_instruction, sti_without_label_2)
{
    char const instruction[] = "sti r3,%3, %:hi";
    char const *expected[] = {
        "sti", "r3", "%3", "%:hi", NULL
    };
    char **actual = NULL;

    actual = parse_instruction(instruction);
    for (int i = 0 ; expected[i] ; i++) {
        cr_assert_str_eq(expected[i], actual[i]);
        free(actual[i]);
    }
    free(actual);
}

Test(parse_instruction, sti_without_label_3)
{
    char const instruction[] = "sti r3,%3,%:hi";
    char const *expected[] = {
        "sti", "r3", "%3", "%:hi", NULL
    };
    char **actual = NULL;

    actual = parse_instruction(instruction);
    for (int i = 0 ; expected[i] ; i++) {
        cr_assert_str_eq(expected[i], actual[i]);
        free(actual[i]);
    }
    free(actual);
}

Test(parse_instruction, sti_without_label_4)
{
    char const instruction[] = "sti r3,%3,%:hi";
    char const *expected[] = {
        "sti", "r3", "%3", "%:hi", NULL
    };
    char **actual = NULL;

    actual = parse_instruction(instruction);
    for (int i = 0 ; expected[i] ; i++) {
        cr_assert_str_eq(expected[i], actual[i]);
        free(actual[i]);
    }
    free(actual);
}

Test(parse_instruction, empty_instruction)
{
    char const instruction[] = "";
    char **actual = NULL;

    actual = parse_instruction(instruction);
    cr_assert_str_empty(actual[0]);
    free(actual);
}

Test(parse_instruction, just_label)
{
    char const instruction[] = "hi:  ";
    char const *expected[] = {
        "hi:", NULL
    };
    char **actual = NULL;

    actual = parse_instruction(instruction);
    for (int i = 0 ; expected[i] ; i++) {
        cr_assert_str_eq(expected[i], actual[i]);
        free(actual[i]);
    }
    free(actual);
}