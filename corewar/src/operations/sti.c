/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Execute an 'sti' instruction
*/

#include "vm.h"

int sti(vm_t *vm, champion_t *champion)
{
    int offset_1 = 0;
    int offset_2 = 0;
    int value = 0;
    int address = 0;
    int reg_nb = 0;

    reg_nb   = champion->instruction->args[0].value;
    value    = champion->regs[reg_nb - 1];
    offset_1 = champion->instruction->args[1].value;
    offset_2 = champion->instruction->args[2].value;
    for (unsigned long int i = 0 ; i < sizeof(int) ; i++) {
        address = (champion->pc+ (offset_1 + offset_2 + i) % IDX_MOD)% MEM_SIZE;
        vm->mem[address] = (unsigned char)(value >> (24 - (i * 8)));
    }
    return (EXIT_SUCCESS);
}