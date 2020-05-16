/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Execute an 'and' instruction
*/

#include "vm.h"

int and(vm_t *vm, proc_t *proc)
{
    int reg_nb = 0;
    int left_operand = 0;
    int right_operand = 0;

    left_operand =  argument_get_value(vm->mem, proc, 0, IDX_MOD);
    right_operand = argument_get_value(vm->mem, proc, 1, IDX_MOD);
    reg_nb = proc->instruction->args[2].value;
    proc->regs[reg_nb - 1] = left_operand & right_operand;
    return (proc->regs[reg_nb - 1]);
}