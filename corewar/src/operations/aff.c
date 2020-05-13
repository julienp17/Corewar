/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Execute an 'aff' instruction
*/

#include "vm.h"
#include "my.h"

int aff(vm_t *vm, champion_t *champion)
{
    int reg_nb = 0;
    int value = 0;

    (void)vm;
    reg_nb = champion->instruction->args[0].value;
    value = champion->regs[reg_nb - 1];
    my_putchar(value % 256);
    return (EXIT_SUCCESS);
}