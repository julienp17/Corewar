/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test unit st operation
*/

#include <criterion/criterion.h>
#include "stdio.h"
#include "vm.h"
#include "my.h"
#include "corewar.h"
#include "operation.h"

Test(st, regiser_to_address)
{
    vm_t *vm = NULL;
    proc_t *proc = NULL;

    vm = vm_create();
    proc = proc_create(0);
    proc->instruction->args[0].type = T_REG;
    proc->instruction->args[0].value = 2;
    proc->instruction->args[1].type = T_IND;
    proc->instruction->args[1].value = 5;
    proc->pc = 0;
    st(vm, proc);
    cr_assert_eq(proc->regs[2], vm->mem[0]);
}

Test(st, store_regiser_in_register)
{
    vm_t *vm = NULL;
    proc_t *proc = NULL;

    vm = vm_create();
    proc = proc_create(0);
    proc->instruction->args[0].type = T_REG;
    proc->instruction->args[0].value = 2;
    proc->instruction->args[1].type = T_REG;
    proc->instruction->args[1].value = 5;
    st(vm, proc);
    cr_assert_eq(proc->regs[2], proc->regs[5]);
}