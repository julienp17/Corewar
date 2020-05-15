/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Execute an 'sti' instruction
*/

#include "vm.h"

static int get_total_offset(char mem[MEM_SIZE], proc_t *proc);
static int get_offset(char mem[MEM_SIZE], proc_t *proc, arg_t *arg);

int sti(vm_t *vm, proc_t *proc)
{
    int offset = 0;
    char to_store = 0;
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

    offset_1 = get_offset(mem, proc, &(proc->instruction->args[1]));
    offset_2 = get_offset(mem, proc, &(proc->instruction->args[2]));
    offset = offset_1 + offset_2;
    return (offset);
}

static int get_offset(char mem[MEM_SIZE], proc_t *proc, arg_t *arg)
{
    int reg_nb = 0;
    int offset = 0;

    if (arg->type == T_REG) {
        reg_nb = arg->value;
        offset = proc->regs[reg_nb - 1];
    } else if (arg->type == T_DIR) {
        offset = arg->value;
    } else {
        offset = get_mem_value(mem, get_index(proc->pc, arg->value, IDX_MOD));
    }
    return (offset);
}