/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Load the next command of a champion
*/

#include "vm.h"
#include "corewar.h"

static bool args_are_correct(op_t op, arg_t args[MAX_ARGS_NUMBER]);
static void fill_args_meta(instruction_t *instruction, uchar coding_byte);
static void fill_args_value(instruction_t *instruction, char mem[MEM_SIZE],
                            int pc);

int champion_load_instruction(char mem[MEM_SIZE], champion_t *champion)
{
    instruction_t *instruction = NULL;
    uchar coding_byte = 0;

    instruction = champion->instruction;
    instruction_reset(instruction);
    instruction->op = op_get_by_code(mem[champion->pc]);
    if (op_is_null(instruction->op))
        return (EXIT_FAILURE);
    instruction->size++;
    if (op_has_coding_byte(instruction->op))
        coding_byte = mem[champion->pc + instruction->size++];
    else
        coding_byte = NO_CB_MASK;
    fill_args_meta(instruction, coding_byte);
    fill_args_value(instruction, mem, champion->pc);
    if (args_are_correct(instruction->op, instruction->args) == false)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

static bool args_are_correct(op_t op, arg_t args[MAX_ARGS_NUMBER])
{
    int nb_args = 0;

    for (int i = 0 ; i < MAX_ARGS_NUMBER ; i++)
        if (args[i].type != 0)
            nb_args++;
    if (nb_args != op.nbr_args)
        return (false);
    for (int i = 0 ; i < op.nbr_args ; i++)
        if ((args[i].type & op.type[i]) == 0)
            return (false);
    return (true);
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

static void fill_args_value(instruction_t *instruction, char mem[MEM_SIZE],
                            int pc)
{
    char buf[sizeof(int)] = {0, 0, 0, 0};
    arg_t *arg = NULL;
    int index = 0;
    int address = 0;

    for (int i = 0 ; i < instruction->op.nbr_args ; i++) {
        arg = &(instruction->args[i]);
        for (int j = 0 ; j < arg->size ; j++) {
            address = (pc + instruction->size++) % MEM_SIZE;
            buf[j] = mem[address];
        }
        if (arg->type == T_REG)
            arg->value = buf[0];
        if (arg->type == T_IND)
            arg->value = swap_int16(*(short int *)(buf));
        if (arg->type == T_DIR) {
            if (argument_is_index(instruction->op))
                arg->value = swap_int16(*(short int *)(buf));
            else
                arg->value = swap_int32(*(int *)buf);
        }
    }
}