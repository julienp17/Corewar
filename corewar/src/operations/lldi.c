/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Execute an 'lldi' instruction
*/

#include "vm.h"

static int get_total_offset(char mem[MEM_SIZE], proc_t *proc);

int lldi(vm_t *vm, proc_t *proc)
{
    int offset = 0;
    int address = 0;
    int reg_nb = 0;

    offset = get_total_offset(vm->mem, proc);
    address = get_index(proc->pc, offset, 0);
    reg_nb = proc->instruction->args[2].value;
    proc->regs[reg_nb - 1] = get_mem_value(vm->mem, address);
    return (proc->regs[reg_nb - 1]);
}

static int get_total_offset(char mem[MEM_SIZE], proc_t *proc)
{
    int offset = 0;
    int offset_1 = 0;
    int offset_2 = 0;

    offset_1 = argument_get_value(mem, proc, 0, IDX_MOD);
    offset_2 = argument_get_value(mem, proc, 1, 0);
    offset = offset_1 + offset_2;
    return (offset);
}