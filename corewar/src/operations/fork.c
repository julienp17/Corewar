/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Execute a 'fork' instruction
*/

#include "vm.h"

int fork(vm_t *vm, champion_t *champion)
{
    int index = 0;

    index = get_index(champion->pc, champion->instruction->args[0].value);
    return (EXIT_SUCCESS);
}