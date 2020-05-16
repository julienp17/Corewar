/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Execute an 'sti' instruction
*/

#include "vm.h"

static int get_total_offset(char mem[MEM_SIZE], proc_t *proc);

int sti(vm_t *vm, proc_t *proc)
{
    int offset = 0;
    int to_store = 0;
    int reg_nb = 0;

    reg_nb = proc->instruction->args[0].value;
    to_store = proc->regs[reg_nb - 1];
    offset = get_total_offset(vm->mem, proc);
    set_mem_value(vm->mem, get_index(proc->pc, offset, IDX_MOD), to_store);
    return (EXIT_SUCCESS);
}

static int get_total_offset(char mem[MEM_SIZE], proc_t *proc)
{
    int offset = 0;
    int offset_1 = 0;
    int offset_2 = 0;

    offset_1 = argument_get_value(mem, proc, 1, IDX_MOD);
    offset_2 = argument_get_value(mem, proc, 2, 0);
    offset = offset_1 + offset_2;
    return (offset);
}