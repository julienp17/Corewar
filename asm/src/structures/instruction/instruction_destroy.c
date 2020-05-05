/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** Destroys an instruction structure
*/

#include <stdlib.h>
#include "instruction.h"

void instruction_destroy(instruction_t *instruction)
{
    if (instruction->label)
        free(instruction->label);
    free(instruction);
}