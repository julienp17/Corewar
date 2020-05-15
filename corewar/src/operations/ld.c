/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Execute an 'ld' instruction
*/

#include "vm.h"

int ld(vm_t *vm, proc_t *proc)
{
    int value = 0;
    int arg_value = 0;
    int reg_nb = 0;

    arg_value = proc->instruction->args[0].value;
    if (proc->instruction->args[0].type == T_DIR)
        value = arg_value;
    else if (proc->instruction->args[0].type == T_IND)
        value = get_mem_value(vm->mem, get_index(proc->pc, arg_value, IDX_MOD));
    reg_nb = proc->instruction->args[1].value;
    proc->regs[reg_nb - 1] = value;
    return (proc->regs[reg_nb - 1]);
}