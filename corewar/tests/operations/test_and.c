/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** test_and
*/

#include <criterion/criterion.h>
#include "operation.h"

Test(and, simple_and_operation)
{
    int status = 0;
    int expected = 4;
    proc_t *process = proc_create(0);

    process->instruction->args[0].type = T_REG;
    process->instruction->args[1].type = T_REG;
    process->instruction->args[2].type = T_REG;
    process->instruction->args[0].value = 2;
    process->instruction->args[1].value = 3;
    process->instruction->args[2].value = 4;
    process->regs[1] = 5;
    process->regs[2] = 4;
    status = and(NULL, process);
    cr_assert_eq(status, expected);
    cr_assert_eq(process->regs[3], expected);
}

Test(and, and_with_two_negative)
{
    int status = 0;
    int expected = -8;
    proc_t *process = proc_create(0);

    process->instruction->args[0].type = T_REG;
    process->instruction->args[1].type = T_REG;
    process->instruction->args[2].type = T_REG;
    process->instruction->args[0].value = 2;
    process->instruction->args[1].value = 3;
    process->instruction->args[2].value = 4;
    process->regs[1] = -2;
    process->regs[2] = -7;
    status = and(NULL, process);
    cr_assert_eq(status, expected);
    cr_assert_eq(process->regs[3], expected);
}

Test(and, and_with_one_negative)
{
    int status = 0;
    int expected = -30;
    proc_t *process = proc_create(0);

    process->instruction->args[0].type = T_REG;
    process->instruction->args[1].type = T_REG;
    process->instruction->args[2].type = T_REG;
    process->instruction->args[0].value = 2;
    process->instruction->args[1].value = 3;
    process->instruction->args[2].value = 4;
    process->regs[1] = -5;
    process->regs[2] = -30;
    status = and(NULL, process);
    cr_assert_eq(status, expected);
    cr_assert_eq(process->regs[3], expected);
}

Test(and, and_with_big_numbers)
{
    int status = 0;
    int expected = 4786;
    proc_t *process = proc_create(0);

    process->instruction->args[0].type = T_REG;
    process->instruction->args[1].type = T_REG;
    process->instruction->args[2].type = T_REG;
    process->instruction->args[0].value = 2;
    process->instruction->args[1].value = 3;
    process->instruction->args[2].value = 4;
    process->regs[1] = 23231;
    process->regs[2] = 5874;
    status = and(NULL, process);
    cr_assert_eq(status, expected);
    cr_assert_eq(process->regs[3], expected);
}