/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** Destroys an assembler structure
*/

#include "asm.h"
#include "my.h"

void asm_destroy(asm_t *assembler)
{
    free(assembler->input_filename);
    my_free_str_array(assembler->lines);
    for (uint i = 0 ; assembler->instructions[i] ; i++)
        instruction_destroy(assembler->instructions[i]);
    free(assembler);
}