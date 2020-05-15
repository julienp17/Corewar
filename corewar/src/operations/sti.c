/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Execute an 'sti' instruction
*/

#include "vm.h"

static int get_total_offset(arg_t args[MAX_ARGS_NUMBER], int regs[REG_NUMBER]);
static int get_offset(arg_t *arg, int regs[REG_NUMBER]);

int sti(vm_t *vm, proc_t *proc)
{
    int offset = 0;
    int value = 0;
    int address = 0;
    int reg_nb = 0;

    reg_nb = proc->instruction->args[0].value;
    value  = proc->regs[reg_nb - 1];
    if (value % 256 > 127)
        value  = (char)value;
    offset = get_total_offset(proc->instruction->args, proc->regs);
    for (unsigned long int i = 0 ; i < sizeof(int) ; i++) {
        address = get_index(proc->pc, offset + i);
        vm->mem[address] = (value >> (8 * (3 - i))) & 0xFF;
    }
    return (EXIT_SUCCESS);
}

static int get_total_offset(arg_t args[MAX_ARGS_NUMBER], int regs[REG_NUMBER])
{
    int offset = 0;
    int offset_1 = 0;
    int offset_2 = 0;

    offset_1 = get_offset(&(args[1]), regs);
    offset_2 = get_offset(&(args[2]), regs);
    offset = offset_1 + offset_2;
    return (offset);
}

static int get_offset(arg_t *arg, int regs[REG_NUMBER])
{
    int reg_nb = 0;
    int offset = 0;

    if (arg->type == T_REG) {
        reg_nb = arg->value;
        offset = regs[reg_nb - 1];
    } else {
        offset = arg->value;
    }
    return (offset);
}