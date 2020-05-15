/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Execute a 'lfork' instruction
*/

#include "vm.h"

int proc_lfork(vm_t *vm, proc_t *proc)
{
    int index = 0;

    index = get_index(proc->pc, proc->instruction->args[0].value, 0);
    proc->next = proc_create(index);
    for (int i = 0 ; i < REG_NUMBER ; i++)
        proc->next->regs[i] = proc->regs[i];
    proc_load_instruction(vm->mem, proc->next);
    return (EXIT_SUCCESS);
}