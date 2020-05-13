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
    int reg_nb = 0;

    (void)vm;
    value  = champion->instruction->args[0].value;
    reg_nb = champion->instruction->args[1].value;
    champion->regs[reg_nb - 1] = value;
    return (EXIT_SUCCESS);
}