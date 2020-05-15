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
    int address = 0;

    reg_nb = proc->instruction->args[0].value;
    to_store = proc->regs[reg_nb - 1];
    if (proc->instruction->args[1].type == T_REG) {
        reg_nb = proc->instruction->args[1].value;
        proc->regs[reg_nb - 1] = to_store;
    } else if (proc->instruction->args[1].type == T_IND) {
        for (int i = 0 ; i < REG_NUMBER ; i++) {
            address = (proc->instruction->args[1].value + i) % MEM_SIZE;
            vm->mem[address] = (to_store >> (8 * (3 - i))) & 0xFF;
        }
    }
    return (EXIT_SUCCESS);
}