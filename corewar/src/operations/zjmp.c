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

    (void)vm;
    if (champion->carry == false)
        return (EXIT_FAILURE);
    value = champion->instruction->args[0].value;
    if (value > 0)
        index = (champion->pc + value % IDX_MOD) % MEM_SIZE;
    else
        index = (champion->pc + value) % MEM_SIZE;
    champion->pc = index;
    champion->instruction->size = 0;
    return (EXIT_SUCCESS);
}