/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Test zjmp
*/

#include <criterion/criterion.h>
#include "vm.h"
#include "operation.h"

Test(zjmp, standard_zjmp_back_with_carry)
{
    proc_t *proc = NULL;
    int status = 0;

    proc = proc_create(0);
    proc->instruction = instruction_create();
    proc->carry = true;
    proc->instruction->args[0].value = -12;
    proc->instruction->size = 3;
    proc->pc = 19;
    status = zjmp(NULL, proc);
    cr_assert_eq(status, EXIT_SUCCESS);
    cr_assert_eq(proc->pc, (19 + -12));
    cr_assert_eq(proc->instruction->size, 0);
}

Test(zjmp, standard_zjmp_forward_with_carry)
{
    proc_t *proc = NULL;
    int status = 0;

    proc = proc_create(0);
    proc->instruction = instruction_create();
    proc->carry = true;
    proc->instruction->args[0].value = 13;
    proc->instruction->size = 3;
    proc->pc = 10;
    status = zjmp(NULL, proc);
    cr_assert_eq(status, EXIT_SUCCESS);
    cr_assert_eq(proc->pc, (10 + 13));
    cr_assert_eq(proc->instruction->size, 0);
}

Test(zjmp, standard_zjmp_zero_with_carry)
{
    proc_t *proc = NULL;
    int status = 0;

    proc = proc_create(0);
    proc->instruction = instruction_create();
    proc->carry = true;
    proc->instruction->args[0].value = 0;
    proc->instruction->size = 3;
    proc->pc = 10;
    status = zjmp(NULL, proc);
    cr_assert_eq(status, EXIT_SUCCESS);
    cr_assert_eq(proc->pc, (10 + 0));
    cr_assert_eq(proc->instruction->size, 0);
}

Test(zjmp, zjmp_back_less_than_mem_with_carry)
{
    proc_t *proc = NULL;
    int status = 0;

    proc = proc_create(0);
    proc->instruction = instruction_create();
    proc->carry = true;
    proc->instruction->args[0].value = -6;
    proc->instruction->size = 3;
    proc->pc = 3;
    status = zjmp(NULL, proc);
    cr_assert_eq(status, EXIT_SUCCESS);
    cr_assert_eq(proc->pc, (MEM_SIZE - 3));
    cr_assert_eq(proc->instruction->size, 0);
}

Test(zjmp, zjmp_forward_more_than_mem_with_carry)
{
    proc_t *proc = NULL;
    int status = 0;

    proc = proc_create(0);
    proc->instruction = instruction_create();
    proc->carry = true;
    proc->instruction->args[0].value = 4;
    proc->instruction->size = 3;
    proc->pc = MEM_SIZE - 2;
    status = zjmp(NULL, proc);
    cr_assert_eq(status, EXIT_SUCCESS);
    cr_assert_eq(proc->pc, (2));
    cr_assert_eq(proc->instruction->size, 0);
}

Test(zjmp, zjmp_no_carry)
{
    proc_t *proc = NULL;
    int status = 0;

    proc = proc_create(0);
    proc->instruction = instruction_create();
    proc->carry = false;
    proc->instruction->args[0].value = -6;
    proc->instruction->size = 3;
    proc->pc = 3;
    status = zjmp(NULL, proc);
    cr_assert_eq(status, EXIT_FAILURE);
    cr_assert_eq(proc->pc, proc->pc);
    cr_assert_eq(proc->instruction->size, proc->instruction->size);
}