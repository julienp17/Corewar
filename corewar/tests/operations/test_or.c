/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** test_or
*/

#include <criterion/criterion.h>
#include "operation.h"

Test(or, simple_or_operation)
{
    int status = 0;
    int expected = 13;
    proc_t *process = proc_create(0);

    process->instruction->args[0].type = T_REG;
    process->instruction->args[1].type = T_REG;
    process->instruction->args[2].type = T_REG;
    process->instruction->args[0].value = 2;
    process->instruction->args[1].value = 3;
    process->instruction->args[2].value = 4;
    process->regs[1] = 5;
    process->regs[2] = 8;
    status = or(NULL, process);
    cr_assert_eq(status, expected);
    cr_assert_eq(process->regs[3], expected);
}

Test(or, or_with_two_negative)
{
    int status = 0;
    int expected = -5;
    proc_t *process = proc_create(0);

    process->instruction->args[0].type = T_REG;
    process->instruction->args[1].type = T_REG;
    process->instruction->args[2].type = T_REG;
    process->instruction->args[0].value = 2;
    process->instruction->args[1].value = 3;
    process->instruction->args[2].value = 4;
    process->regs[1] = -21;
    process->regs[2] = -38;
    status = or(NULL, process);
    cr_assert_eq(status, expected);
    cr_assert_eq(process->regs[3], expected);
}

Test(or, or_with_one_negative)
{
    int status = 0;
    int expected = -90;
    proc_t *process = proc_create(0);

    process->instruction->args[0].type = T_REG;
    process->instruction->args[1].type = T_REG;
    process->instruction->args[2].type = T_REG;
    process->instruction->args[0].value = 2;
    process->instruction->args[1].value = 3;
    process->instruction->args[2].value = 4;
    process->regs[1] = 6;
    process->regs[2] = -94;
    status = or(NULL, process);
    cr_assert_eq(status, expected);
    cr_assert_eq(process->regs[3], expected);
}

Test(or, or_with_big_numbers)
{
    int status = 0;
    int expected = 1007263;
    proc_t *process = proc_create(0);

    process->instruction->args[0].type = T_REG;
    process->instruction->args[1].type = T_REG;
    process->instruction->args[2].type = T_REG;
    process->instruction->args[0].value = 2;
    process->instruction->args[1].value = 3;
    process->instruction->args[2].value = 4;
    process->regs[1] = 859674;
    process->regs[2] = 154263;
    status = or(NULL, process);
    cr_assert_eq(status, expected);
    cr_assert_eq(process->regs[3], expected);
}