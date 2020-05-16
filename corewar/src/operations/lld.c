/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Execute an 'lld' instruction
*/

#include "vm.h"

int lld(vm_t *vm, proc_t *proc)
{
    int value = 0;
    int reg_nb = 0;

    value = argument_get_value(vm->mem, proc, 0, 0);
    reg_nb = proc->instruction->args[1].value;
    proc->regs[reg_nb - 1] = value;
    return (proc->regs[reg_nb - 1]);
}