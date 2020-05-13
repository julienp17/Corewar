/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Execute an 'st' instruction
*/

#include "vm.h"
#include "my.h"

int st(vm_t *vm, champion_t *champion)
{
    int reg_nb = 0;
    int to_store = 0;
    int address = 0;

    reg_nb = champion->instruction->args[0].value;
    to_store = champion->regs[reg_nb - 1];
    if (champion->instruction->args[1].type == T_REG) {
        reg_nb = champion->instruction->args[1].value;
        champion->regs[reg_nb - 1] = to_store;
    } else if (champion->instruction->args[1].type == T_IND) {
        address = get_index(champion->pc, champion->instruction->args[1].value);
        vm->mem[address] = to_store;
    }
    return (EXIT_SUCCESS);
}