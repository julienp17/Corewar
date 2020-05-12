/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Reinitialize the instruction structure fields to 0
*/

#include "instruction.h"

void instruction_reset(instruction_t *instruction)
{
    instruction->op = (op_t) {0, 0, {0}, 0, 0, 0};
    for (int i = 0 ; i < MAX_ARGS_NUMBER ; i++) {
        instruction->args[i].type = 0;
        instruction->args[i].size = 0;
        instruction->args[i].value = 0;
    }
}