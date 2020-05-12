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
    int value = 0;

    if (champion->carry == false)
        return (EXIT_FAILURE);
    (void)vm;
    value = champion->instruction->args[0].value;
    index = champion->pc + value % IDX_MOD;
    champion->pc = index;
    return (EXIT_SUCCESS);
}