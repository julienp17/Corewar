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

    status = asm_fill_header(assembler);
    if (status == EXIT_FAILURE)
        return (EXIT_FAILURE);
    // my_strarr_put(assembler->lines);
    // asm_puterr(assembler, "no errors");
    return (status);
}