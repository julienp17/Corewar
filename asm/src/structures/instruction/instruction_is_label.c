/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** Returns true if an instruction is only composed of a label
*/

#include <stddef.h>
#include "instruction.h"

bool instruction_is_label(instruction_t const *instruction)
{
    return (instruction->label != NULL && instruction->op.mnemonique == 0);
}