/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Load the next command of a champion
*/

#include "vm.h"
#include "corewar.h"

static int load_instruction(char mem[MEM_SIZE], champion_t *champion);
static void fill_args_meta(instruction_t *instruction, uchar coding_byte);
static void fill_arg_value(char mem[MEM_SIZE], champion_t *champion,arg_t *arg);

int champion_load_instruction(char mem[MEM_SIZE], champion_t *champion)
{
    int status = 0;

    champion->pc = champion->pc + champion->instruction->size;
    instruction_reset(champion->instruction);
    status = load_instruction(mem, champion);
    if (status == EXIT_SUCCESS)
        champion->cycle_wait = champion->instruction->op.nbr_cycles;
    else
        champion->cycle_wait = 1;
    return (status);
}

static int load_instruction(char mem[MEM_SIZE], champion_t *champion)
{
    instruction_t *instruction = NULL;
    uchar coding_byte = 0;

    instruction = champion->instruction;
    instruction->op = op_get_by_code(mem[champion->pc]);
    if (op_is_null(instruction->op))
        return (EXIT_FAILURE);
    instruction->size++;
    if (op_has_coding_byte(instruction->op))
        coding_byte = mem[champion->pc + instruction->size++];
    else
        coding_byte = NO_CB_MASK;
    fill_args_meta(instruction, coding_byte);
    for (int i = 0 ; i < instruction->op.nbr_args ; i++)
        fill_arg_value(mem, champion, &(instruction->args[i]));
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

static void fill_arg_value(char mem[MEM_SIZE], champion_t *champion, arg_t *arg)
{
    char buf[sizeof(int)] = {0, 0, 0, 0};
    int address = 0;

    for (int j = 0 ; j < arg->size ; j++) {
        address = (champion->pc + champion->instruction->size++) % MEM_SIZE;
        buf[j] = mem[address];
    }
    if (arg->type == T_REG)
        arg->value = buf[0];
    if (arg->type == T_IND) {
        arg->value = swap_int16(*(short int *)(buf));
        arg->value = (champion->pc + arg->value % IDX_MOD) % MEM_SIZE;
    }
    if (arg->type == T_DIR) {
        if (argument_is_index(champion->instruction->op))
            arg->value = swap_int16(*(short int *)(buf));
        else
            arg->value = swap_int32(*(int *)buf);
    }
}