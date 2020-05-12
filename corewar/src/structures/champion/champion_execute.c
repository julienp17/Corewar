/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Execute the command as a champion
*/

#include "vm.h"
#include "corewar.h"

static void fill_args_meta(instruction_t *instruction, uchar coding_byte);

int champion_execute(vm_t *vm, champion_t *champion)
{
    instruction_t *instruction = NULL;
    uchar coding_byte = 0;
    char buf[sizeof(int)] = {0, 0, 0, 0};

    instruction = champion->instruction;
    instruction_reset(instruction);
    instruction->op = op_get_by_code(vm->mem[champion->pc++]);
    if (op_is_null(instruction->op)) {
        champion->cycle_wait = 1;
        return (EXIT_FAILURE);
    }
    if (op_has_coding_byte(instruction->op))
        coding_byte = vm->mem[champion->pc++];
    else
        coding_byte = NO_CB_MASK;
    fill_args_meta(instruction, coding_byte);
    for (int i = 0 ; i < instruction->op.nbr_args ; i++) {
        for (int j = 0 ; j < instruction->args[i].size ; j++)
            buf[j] = vm->mem[champion->pc++];
        if (instruction->args[i].type == T_REG)
            instruction->args[i].value = buf[0];
        if (instruction->args[i].type == T_IND)
            instruction->args[i].value = swap_int16(*(short int *)(buf));
        if (instruction->args[i].type == T_DIR) {
            if (argument_is_index(instruction->op))
                instruction->args[i].value = swap_int16(*(short int *)(buf));
            else
                instruction->args[i].value = swap_int32(*(int *)buf);
        }
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
        instruction->args[i].size = argument_get_size(instruction->args[i].type,
                                                    instruction->op);
    }
}