/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Unit tests for asm create
*/

#include <criterion/criterion.h>
#include "asm.h"

Test(asm_create, abel)
{
    asm_t *assembler = NULL;
    char const input_filename[] = "reference/src/abel.s";
    char const *expected_lines[] = {
        ".name \"Abel\"",
        ".comment \"L\'amer noir.\"",
        "",
        "",
        "sti r1, %:hi, %1",
        "hi: live %234",
        "ld %0, r3",
        "zjmp %:hi",
        NULL
    };

    assembler = asm_create(input_filename);
    cr_assert_not_null(assembler);
    cr_assert_str_eq(assembler->input_filename, input_filename);
    cr_assert_eq(assembler->line, 0);
    cr_assert_eq(assembler->nb_instructions, 0);
    cr_assert_null(assembler->instructions);
    for (int i = 0 ; expected_lines[i] ; i++)
        cr_assert_str_eq(assembler->lines[i], expected_lines[i]);
    cr_assert_eq(assembler->header.magic, swap_int32(COREWAR_EXEC_MAGIC));
    cr_assert_str_empty(assembler->header.prog_name);
    cr_assert_eq(assembler->header.prog_size, 0);
    cr_assert_str_empty(assembler->header.comment);
}

Test(asm_create, tyron)
{
    asm_t *assembler = NULL;
    char const input_filename[] = "reference/src/tyron.s";
    char const *expected_lines[] = {
        ".name \"Tyron\"",
        ".comment \"Just a basic pompes, traction program\"",
        "",
        "",
        "sti r1, %:hi, %1",
        "hi: live %123",
        "ld %0, r3",
        "zjmp %:hi",
        NULL
    };

    assembler = asm_create(input_filename);
    cr_assert_not_null(assembler);
    cr_assert_str_eq(assembler->input_filename, input_filename);
    cr_assert_eq(assembler->line, 0);
    cr_assert_eq(assembler->nb_instructions, 0);
    cr_assert_null(assembler->instructions);
    for (int i = 0 ; expected_lines[i] ; i++)
        cr_assert_str_eq(assembler->lines[i], expected_lines[i]);
    cr_assert_eq(assembler->header.magic, swap_int32(COREWAR_EXEC_MAGIC));
    cr_assert_str_empty(assembler->header.prog_name);
    cr_assert_eq(assembler->header.prog_size, 0);
    cr_assert_str_empty(assembler->header.comment);
}