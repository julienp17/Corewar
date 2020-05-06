/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** Returns true if the assembler has atleast one instruction filled with data
*/

#include "asm.h"

bool asm_has_an_instruction(asm_t *asb)
{
    for (uint i = 0 ; asb->instructions[i] ; i++) {
        if (!instruction_is_label(asb->instructions[i])
                && asb->instructions[i]->args[0].type != 0)
        return (true);
    }
    return (false);
}