/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Execute an 'sti' instruction
*/

#include "vm.h"

int sti(vm_t *vm, proc_t *proc)
{
    int offset_1 = 0;
    int offset_2 = 0;
    int offset = 0;
    int value = 0;
    int address = 0;
    int reg_nb = 0;

    reg_nb   = proc->instruction->args[0].value;
    value    = proc->regs[reg_nb - 1];
    if (value % 256 > 127)
        value  = (char)value;
    offset_1 = proc->instruction->args[1].value;
    offset_2 = proc->instruction->args[2].value;
    offset   = offset_1 + offset_2;
    for (unsigned long int i = 0 ; i < sizeof(int) ; i++) {
        address = get_index(proc->pc, offset + i);
        vm->mem[address] = (value >> (8 * (3 - i))) & 0xFF;
    }
    return (EXIT_SUCCESS);
}