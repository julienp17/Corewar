/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Execute an 'st' instruction
*/

#include "vm.h"
#include "my.h"

int st(vm_t *vm, proc_t *proc)
{
    int reg_nb = 0;
    int to_store = 0;
    int value = 0;

    reg_nb = proc->instruction->args[0].value;
    to_store = proc->regs[reg_nb - 1];
    if (proc->instruction->args[1].type == T_REG) {
        reg_nb = proc->instruction->args[1].value;
        proc->regs[reg_nb - 1] = to_store;
    } else if (proc->instruction->args[1].type == T_IND) {
        value = proc->instruction->args[1].value;
        set_mem_value(vm->mem, get_index(proc->pc, value, IDX_MOD), to_store);
    }
    return (EXIT_SUCCESS);
}