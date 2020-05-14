/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Execute a 'zjmp' instruction
*/

#include "vm.h"

int zjmp(vm_t *vm, proc_t *proc)
{
    int index = 0;

    (void)vm;
    if (proc->carry == false)
        return (EXIT_FAILURE);
    index = get_index(proc->pc, proc->instruction->args[0].value);
    proc->pc = index;
    proc->instruction->size = 0;
    return (EXIT_SUCCESS);
}