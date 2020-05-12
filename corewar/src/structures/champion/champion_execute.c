/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Execute the command as a champion
*/

#include "vm.h"
#include "corewar.h"
#include "operation.h"

int champion_execute(vm_t *vm, champion_t *champion)
{
    int (*operation)(vm_t *, champion_t *) = NULL;
    int status = 0;

    champion_load_instruction(vm, champion);
    operation = operation_get(champion->instruction->op.code);
    if (operation == NULL) {
        champion->cycle_wait = 1;
        return (EXIT_FAILURE);
    }
    status = operation(vm, champion);
    if (op_modifies_carry(champion->instruction->op))
        champion->carry = status;
    champion->cycle_wait = champion->instruction->op.nbr_cycles;
    champion->pc = (champion->pc + champion->instruction->size) % MEM_SIZE;
    return (status);
}
