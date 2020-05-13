/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Execute a 'zjmp' instruction
*/

#include "vm.h"

int zjmp(vm_t *vm, champion_t *champion)
{
    int value = 0;

    (void)vm;
    if (champion->carry == false)
        return (EXIT_FAILURE);
    value = champion->instruction->args[0].value;
    if (value > 0)
        champion->pc += value % IDX_MOD;
    else
        champion->pc += value;
    if (champion->pc < 0)
        champion->pc += MEM_SIZE;
    else if (champion->pc > MEM_SIZE)
        champion->pc %= MEM_SIZE;
    champion->instruction->size = 0;
    return (EXIT_SUCCESS);
}