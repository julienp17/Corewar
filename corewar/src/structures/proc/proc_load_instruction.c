/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Load the next instruction of a process
*/

#include "vm.h"
#include "corewar.h"

static int load_instruction(char mem[MEM_SIZE], proc_t *proc);
static void fill_args_meta(instruction_t *instruction, uchar coding_byte);
static void fill_arg_value(char mem[MEM_SIZE], proc_t *proc, arg_t *arg);

int proc_load_instruction(char mem[MEM_SIZE], proc_t *proc)
{
    int status = 0;

    proc->pc = (proc->pc + proc->instruction->size) % MEM_SIZE;
    instruction_reset(proc->instruction);
    status = load_instruction(mem, proc);
    if (status == EXIT_SUCCESS) {
        proc->cycle_wait = proc->instruction->op.nbr_cycles;
    } else {
        proc->cycle_wait = 2;
        proc->pc = (proc->pc + 1) % MEM_SIZE;
    }
    return (status);
}

static int load_instruction(char mem[MEM_SIZE], proc_t *proc)
{
    instruction_t *instruction = NULL;
    uchar coding_byte = 0;

    instruction = proc->instruction;
    instruction->op = op_get_by_code(mem[proc->pc]);
    if (op_is_null(instruction->op))
        return (EXIT_FAILURE);
    instruction->size++;
    if (op_has_coding_byte(instruction->op))
        coding_byte = mem[proc->pc + instruction->size++];
    else
        coding_byte = NO_CB_MASK;
    fill_args_meta(instruction, coding_byte);
    for (int i = 0 ; i < instruction->op.nbr_args ; i++)
        fill_arg_value(mem, proc, &(instruction->args[i]));
    if (arguments_are_correct(instruction->op, instruction->args) == false) {
        instruction->op = (op_t) {0, 0, {0}, 0, 0, 0};
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

static void fill_args_meta(instruction_t *instruction, uchar coding_byte)
{
    instruction->args[0].type = (coding_byte & 0b11000000) >> 6;
    instruction->args[1].type = (coding_byte & 0b00110000) >> 4;
    instruction->args[2].type = (coding_byte & 0b00001100) >> 2;
    instruction->args[3].type = (coding_byte & 0b00000011);
    for (int i = 0 ; i < instruction->op.nbr_args ; i++) {
        if (instruction->args[i].type == 0b11)
            instruction->args[i].type = T_IND;
        instruction->args[i].size = argument_get_size(instruction->args[i].type,
                                                    instruction->op);
    }
}

static void fill_arg_value(char mem[MEM_SIZE], proc_t *proc, arg_t *arg)
{
    char buf[sizeof(int)] = {0, 0, 0, 0};
    int address = 0;
    int value = 0;

    for (int j = 0 ; j < arg->size ; j++) {
        address = (proc->pc + proc->instruction->size++) % MEM_SIZE;
        buf[j] = mem[address];
    }
    if (arg->type == T_REG)
        arg->value = buf[0];
    if (arg->type == T_IND) {
        value = swap_int16(*(short int *)(buf));
        for (int i = 0 ; i < REG_SIZE ; i++) {
            address = get_index(proc->pc, value + i);
            arg->value = (arg->value << 8) + mem[address];
        }
    }
    if (arg->type == T_DIR) {
        if (argument_is_index(proc->instruction->op))
            arg->value = swap_int16(*(short int *)(buf));
        else
            arg->value = swap_int32(*(int *)buf);
    }
}