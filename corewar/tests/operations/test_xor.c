/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** test_xor
*/

#include <criterion/criterion.h>
#include "operation.h"

Test(xor, simple_xor_operation)
{
    int status = 0;
    int expected = 4;
    proc_t *process = proc_create(0);

    process->instruction->args[0].value = 2;
    process->instruction->args[1].value = 3;
    process->instruction->args[2].value = 4;
    process->regs[1] = 7;
    process->regs[2] = 3;
    status = xor(NULL, process);
    cr_assert_eq(status, expected);
    cr_assert_eq(process->regs[3], expected);
}

Test(xor, xor_with_two_negative)
{
    int status = 0;
    int expected = 33;
    proc_t *process = proc_create(0);

    process->instruction->args[0].value = 2;
    process->instruction->args[1].value = 3;
    process->instruction->args[2].value = 4;
    process->regs[1] = -56;
    process->regs[2] = -23;
    status = xor(NULL, process);
    cr_assert_eq(status, expected);
    cr_assert_eq(process->regs[3], expected);
}

Test(xor, xor_with_one_negative)
{
    int status = 0;
    int expected = -72;
    proc_t *process = proc_create(0);

    process->instruction->args[0].value = 2;
    process->instruction->args[1].value = 3;
    process->instruction->args[2].value = 4;
    process->regs[1] =   -14;
    process->regs[2] = 74;
    status = xor(NULL, process);
    cr_assert_eq(status, expected);
    cr_assert_eq(process->regs[3], expected);
}

Test(xor, xor_with_big_numbers)
{
    int status = 0;
    int expected = 729939;
    proc_t *process = proc_create(0);

    process->instruction->args[0].value = 2;
    process->instruction->args[1].value = 3;
    process->instruction->args[2].value = 4;
    process->regs[1] = 658214;
    process->regs[2] = 75893;
    status = xor(NULL, process);
    cr_assert_eq(status, expected);
    cr_assert_eq(process->regs[3], expected);
}