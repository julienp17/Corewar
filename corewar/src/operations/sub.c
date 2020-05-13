/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Execute a 'sub' instruction
*/

#include "vm.h"
#include "my.h"

int sub(vm_t *vm, champion_t *champion)
{
    int reg_nb = 0;
    int add1 = 0;
    int add2 = 0;

    reg_nb = champion->instruction->args[0].value;
    add1 = champion->regs[reg_nb - 1];
    reg_nb = champion->instruction->args[1].value;
    add2 = champion->regs[reg_nb - 1];
    reg_nb = champion->instruction->args[2].value;
    champion->regs[reg_nb - 1] = add1 - add2;
    return (EXIT_SUCCESS);
}