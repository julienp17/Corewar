/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Execute an 'ld' instruction
*/

#include "vm.h"

int ld(vm_t *vm, champion_t *champion)
{
    int value = 0;
    int address = 0;
    int reg_nb = 0;

    if (champion->instruction->args[0].type == T_IND) {
        value = champion->instruction->args[0].value;
    } else if (champion->instruction->args[0].type == T_DIR) {
        address =(champion->pc + champion->instruction->args[0].value)%MEM_SIZE;
        value = vm->mem[address];
    }
    reg_nb = champion->instruction->args[1].value;
    champion->regs[reg_nb] = value;
    return (EXIT_SUCCESS);
}