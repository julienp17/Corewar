/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** Unit tests for instruction_is_correct
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "asm.h"


Test(instruction_is_correct, correct_sti_without_label)
{
    char const instruction[] = "sti r1, 2, %1";
    bool expected = true;
    bool actual = false;
    asm_t asb;

    asb.input_filename = "test";
    asb.line = 3;
    actual = instruction_is_correct(&asb, instruction);
    cr_assert_eq(actual, expected);
}

Test(instruction_is_correct, correct_sti_with_label)
{
    char const instruction[] = "hi: sti r1, %:hi, %1";
    bool expected = true;
    bool actual = false;
    asm_t asb;

    asb.input_filename = "test";
    asb.line = 3;
    actual = instruction_is_correct(&asb, instruction);
    cr_assert_eq(actual, expected);
}

Test(instruction_is_correct, correct_reg_number)
{
    char const instruction[] = "aff r3";
    bool expected = true;
    bool actual = false;
    asm_t asb;

    asb.input_filename = "test";
    asb.line = 3;
    actual = instruction_is_correct(&asb, instruction);
    cr_assert_eq(actual, expected);
}

Test(instruction_is_correct, empty_instruction, .init = cr_redirect_stderr)
{
    char const instruction[] = "";
    char const expected_str[] = \
        "\e[1masm, test, line 4: \e[91mInvalid instruction.\e[0m\n";
    bool expected = false;
    bool actual = false;
    asm_t asb;

    asb.input_filename = "test";
    asb.line = 3;
    actual = instruction_is_correct(&asb, instruction);
    cr_assert_eq(actual, expected);
    cr_assert_stderr_eq_str(expected_str);
}

Test(instruction_is_correct, empty_label, .init = cr_redirect_stderr)
{
    char const instruction[] = ": sti r1, %2, %1";
    char const expected_str[] = \
        "\e[1masm, test, line 4: \e[91mEmpty label.\e[0m\n";
    bool expected = false;
    bool actual = false;
    asm_t asb;

    asb.input_filename = "test";
    asb.line = 3;
    actual = instruction_is_correct(&asb, instruction);
    cr_assert_eq(actual, expected);
    cr_assert_stderr_eq_str(expected_str);
}

Test(instruction_is_correct, invalid_label, .init = cr_redirect_stderr)
{
    char const instruction[] = "Hi: sti r1, %:hi, %1";
    char const expected_str[] = \
        "\e[1masm, test, line 4: \e[91mInvalid label name.\e[0m\n";
    bool expected = false;
    bool actual = false;
    asm_t asb;

    asb.input_filename = "test";
    asb.line = 3;
    actual = instruction_is_correct(&asb, instruction);
    cr_assert_eq(actual, expected);
    cr_assert_stderr_eq_str(expected_str);
}

Test(instruction_is_correct, unknown_instruction, .init = cr_redirect_stderr)
{
    char const instruction[] = "mv r1, r2";
    char const expected_str[] = \
        "\e[1masm, test, line 4: \e[91mInvalid instruction.\e[0m\n";
    bool expected = false;
    bool actual = false;
    asm_t asb;

    asb.input_filename = "test";
    asb.line = 3;
    actual = instruction_is_correct(&asb, instruction);
    cr_assert_eq(actual, expected);
    cr_assert_stderr_eq_str(expected_str);
}

Test(instruction_is_correct, too_much_parameters, .init = cr_redirect_stderr)
{
    char const instruction[] = "ld %0, r3, 04";
    char const expected_str[] = \
        "\e[1masm, test, line 4: \e[91mToo many arguments given to the " \
        "instruction.\e[0m\n";
    bool expected = false;
    bool actual = false;
    asm_t asb;

    asb.input_filename = "test";
    asb.line = 3;
    actual = instruction_is_correct(&asb, instruction);
    cr_assert_eq(actual, expected);
    cr_assert_stderr_eq_str(expected_str);
}

Test(instruction_is_correct, not_enough_parameters, .init = cr_redirect_stderr)
{
    char const instruction[] = "ld %0";
    char const expected_str[] = \
        "\e[1masm, test, line 4: \e[91mToo many arguments given to the " \
        "instruction.\e[0m\n";
    bool expected = false;
    bool actual = false;
    asm_t asb;

    asb.input_filename = "test";
    asb.line = 3;
    actual = instruction_is_correct(&asb, instruction);
    cr_assert_eq(actual, expected);
    cr_assert_stderr_eq_str(expected_str);
}

Test(instruction_is_correct,incorrect_parameter_type, .init=cr_redirect_stderr)
{
    char const instruction[] = "ld r3, r2";
    char const expected_str[] = \
        "\e[1masm, test, line 4: \e[91mThe argument given to the " \
        "instruction is invalid.\e[0m\n";
    bool expected = false;
    bool actual = false;
    asm_t asb;

    asb.input_filename = "test";
    asb.line = 3;
    actual = instruction_is_correct(&asb, instruction);
    cr_assert_eq(actual, expected);
    cr_assert_stderr_eq_str(expected_str);
}

Test(instruction_is_correct, zero_reg_number, .init = cr_redirect_stderr)
{
    char const instruction[] = "aff r0";
    char const expected_str[] = \
        "\e[1masm, test, line 4: \e[91mInvalid register number.\e[0m\n";
    bool expected = false;
    bool actual = false;
    asm_t asb;

    asb.input_filename = "test";
    asb.line = 3;
    actual = instruction_is_correct(&asb, instruction);
    cr_assert_eq(actual, expected);
    cr_assert_stderr_eq_str(expected_str);
}

Test(instruction_is_correct, too_much_reg_number, .init=cr_redirect_stderr)
{
    char const instruction[] = "aff r17";
    char const expected_str[] = \
        "\e[1masm, test, line 4: \e[91mInvalid register number.\e[0m\n";
    bool expected = false;
    bool actual = false;
    asm_t asb;

    asb.input_filename = "test";
    asb.line = 3;
    actual = instruction_is_correct(&asb, instruction);
    cr_assert_eq(actual, expected);
    cr_assert_stderr_eq_str(expected_str);
}

Test(instruction_is_correct, incorrect_sep, .init=cr_redirect_stderr)
{
    char const instruction[] = "ld %-1; r3";
    char const expected_str[] = \
        "\e[1masm, test, line 4: \e[91mThe argument given to the " \
        "instruction is invalid.\e[0m\n";
    bool expected = false;
    bool actual = false;
    asm_t asb;

    asb.input_filename = "test";
    asb.line = 3;
    actual = instruction_is_correct(&asb, instruction);
    cr_assert_eq(actual, expected);
    cr_assert_stderr_eq_str(expected_str);
}