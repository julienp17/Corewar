/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Execute a 'fork' instruction
*/

#include "vm.h"

int proc_fork(vm_t *vm, proc_t *proc)
{
    int index = 0;

    index = get_index(proc->pc, proc->instruction->args[0].value, IDX_MOD);
    proc->next = proc_create(index);
    for (int i = 0 ; i < REG_NUMBER ; i++)
        proc->next->regs[i] = proc->regs[i];
    proc_load_instruction(vm->mem, proc->next);
    return (EXIT_SUCCESS);
}