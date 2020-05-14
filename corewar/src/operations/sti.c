/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Execute an 'sti' instruction
*/

#include "vm.h"
#include <stdio.h>
int sti(vm_t *vm, champion_t *champion)
{
    int offset_1 = 0;
    int offset_2 = 0;
    int offset = 0;
    int value = 0;
    int address = 0;
    int reg_nb = 0;

    reg_nb   = champion->instruction->args[0].value;
    value    = champion->regs[reg_nb - 1];
    offset_1 = champion->instruction->args[1].value;
    offset_2 = champion->instruction->args[2].value;
    offset   = offset_1 + offset_2;
    for (unsigned long int i = 0 ; i < sizeof(int) ; i++) {
        address = get_index(champion->pc, offset + i);
        vm->mem[address] = (unsigned char)(value >> (24 - (i * 8)));
    }
    return (EXIT_SUCCESS);
}