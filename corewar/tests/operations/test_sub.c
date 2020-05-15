/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Test unit sub operation
*/

#include <criterion/criterion.h>
#include "stdio.h"
#include "vm.h"
#include "my.h"
#include "corewar.h"
#include "operation.h"

Test(add, simple_substraction)
{
    vm_t *vm = NULL;
    proc_t *proc = NULL;

    vm = vm_create();
    proc = proc_create(0);
    proc->instruction->args[1].type = T_REG;
    proc->instruction->args[1].value = 2;
    proc->instruction->args[2].type = T_REG;
    proc->instruction->args[2].value = 3;
    proc->instruction->args[3].type = T_REG;

    cr_assert_eq(proc->regs[2], sub(vm, proc));
}