/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Unit tests for 'ld' operation
*/

#include <criterion/criterion.h>
#include "operation.h"

Test(ld, ld_with_direct)
{
    proc_t *proc = NULL;
    int exit_code = 0;
    int expected_value = 14;

    proc = proc_create(0);
    proc->instruction->args[0].type = T_DIR;
    proc->instruction->args[0].value = expected_value;
    proc->instruction->args[1].type = T_REG;
    proc->instruction->args[1].value = 3;
    exit_code = ld(NULL, proc);
    cr_assert_eq(exit_code, expected_value);
    cr_assert_eq(proc->regs[3 - 1], expected_value);
}

Test(ld, ld_with_direct_value_zero)
{
    proc_t *proc = NULL;
    int exit_code = 0;
    int expected_value = 0;

    proc = proc_create(0);
    proc->instruction->args[0].type = T_DIR;
    proc->instruction->args[0].value = expected_value;
    proc->instruction->args[1].type = T_REG;
    proc->instruction->args[1].value = 3;
    exit_code = ld(NULL, proc);
    cr_assert_eq(exit_code, expected_value);
    cr_assert_eq(proc->regs[3 - 1], expected_value);
}

Test(ld, ld_with_indirect_value)
{
    proc_t *proc = NULL;
    int exit_code = 0;
    int expected_value = 14;

    proc = proc_create(0);
    proc->instruction->args[0].type = T_IND;
    proc->instruction->args[0].value = expected_value;
    proc->instruction->args[1].type = T_REG;
    proc->instruction->args[1].value = 3;
    exit_code = ld(NULL, proc);
    cr_assert_eq(exit_code, expected_value);
    cr_assert_eq(proc->regs[3 - 1], expected_value);
}