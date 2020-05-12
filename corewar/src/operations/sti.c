/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Execute an 'sti' instruction
*/

#include "vm.h"

static int get_first_offset(char mem[MEM_SIZE], champion_t *champion);
static int get_second_offset(arg_t arg, int regs[REG_NUMBER]);
#include <stdio.h>
int sti(vm_t *vm, champion_t *champion)
{
    int offset_1 = 0;
    int offset_2 = 0;
    int value = 0;
    int address = 0;
    int reg_nb = 0;

    reg_nb = champion->instruction->args[0].value;
    value = champion->regs[reg_nb];
    offset_1 = get_first_offset(vm->mem, champion);
    offset_2 = get_second_offset(champion->instruction->args[2],champion->regs);
    address = champion->pc + (offset_1 + offset_2) % IDX_MOD;
    printf("%d\n", address);
    vm->mem[address] = value;
    return (EXIT_SUCCESS);
}

static int get_first_offset(char mem[MEM_SIZE], champion_t *champion)
{
    int offset = 0;
    int reg_nb = 0;
    int address = 0;
    arg_t arg = (arg_t) {0, 0, 0};

    arg = champion->instruction->args[1];
    if (arg.type == T_REG) {
        reg_nb = arg.value - 1;
        offset = champion->regs[reg_nb];
    }
    if (arg.type == T_DIR)
        offset = arg.value;
    if (arg.type == T_IND) {
        address = (champion->pc + arg.value) % MEM_SIZE;
        offset = mem[address];
    }
    return (offset);
}

static int get_second_offset(arg_t arg, int regs[REG_NUMBER])
{
    int reg_nb = 0;
    int offset = 0;

    if (arg.type == T_REG) {
        reg_nb = arg.value - 1;
        offset = regs[reg_nb];
    }
    if (arg.type == T_DIR)
        offset = arg.value;
    return (offset);
}