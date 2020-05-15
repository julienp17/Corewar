/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Execute the command as a champion
*/

#include "vm.h"
#include "corewar.h"
#include "operation.h"

static int execute_operation(vm_t *vm, proc_t *proc);

void champion_execute(vm_t *vm, champion_t *champion)
{
    proc_t *proc = NULL;

    proc = champion->proc;
    while (proc != NULL) {
        execute_operation(vm, proc);
        proc = proc->next;
    }
}

static int execute_operation(vm_t *vm, proc_t *proc)
{
    int (*operation)(vm_t *, proc_t *) = NULL;
    int status = 0;

    if (proc->cycle_wait > 1) {
        proc->cycle_wait--;
        return (EXIT_SUCCESS);
    }
    operation = operation_get(proc->instruction->op.code);
    if (operation) {
        status = operation(vm, proc);
        if (op_modifies_carry(proc->instruction->op))
            proc->carry = (status == 0);
    }
    status = proc_load_instruction(vm->mem, proc);
    return (status);
}
