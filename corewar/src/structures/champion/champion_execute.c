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

    if (champion->cycle_wait > 0) {
        champion->cycle_wait--;
        return (EXIT_SUCCESS);
    }
    operation = operation_get(champion->instruction->op.code);
    if (operation) {
        status = operation(vm, champion);
        if (op_modifies_carry(champion->instruction->op))
            champion->carry = (status == EXIT_SUCCESS) ? true : false;
    }
    status = champion_load_instruction(vm->mem, champion);
    return (status);
}
