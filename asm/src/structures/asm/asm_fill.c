/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** Fill the assembler structure while looking for errors
*/

#include "asm.h"
#include "my.h"

int asm_fill(asm_t *assembler)
{
    int status = 0;

    my_strarr_put(assembler->file_lines);
    return (status);
}