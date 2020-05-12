/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Execute a 'zjmp' instruction
*/

#include "vm.h"

int zjmp(vm_t *vm, champion_t *champion)
{
    int index = 0;

    (void)vm;
    if (champion->carry == false)
        return (EXIT_FAILURE);
    index = champion->instruction->args[0].value;
    champion->pc = index;
    return (EXIT_SUCCESS);
}