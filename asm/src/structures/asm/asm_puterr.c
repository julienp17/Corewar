/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** Print an assembler structure error
*/

#include "asm.h"
#include "my.h"

void asm_puterr(asm_t *assembler, char const *error_str)
{
    my_eprintf("\e[1masm, %s, line %d: \e[91m%s.\e[0m\n",
        assembler->input_filename,
        assembler->line + 1,
        error_str
    );
}
