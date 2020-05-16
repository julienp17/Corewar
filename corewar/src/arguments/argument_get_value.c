/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Returns the value of the argument
*/

#include "vm.h"

int argument_get_value(char mem[MEM_SIZE], proc_t *proc, int arg_nb, int flag)
{
    arg_t *arg = NULL;
    int value = 0;

    arg = &(proc->instruction->args[arg_nb]);
    if (arg->type == T_REG)
        value = proc->regs[arg->value - 1];
    if (arg->type == T_DIR)
        value = arg->value;
    if (arg->type == T_IND)
        value = get_mem_value(mem, get_index(proc->pc, arg->value, flag));
    return (value);
}