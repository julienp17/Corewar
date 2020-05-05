/*
** EPITECH PROJECT, 2020
** Corewar Assembler
** File description:
** Assemble an assembler file
*/

#include "asm.h"
#include "file_control.h"
#include "my.h"

int assemble(char const *filename)
{
    asm_t *assembler = NULL;
    int status = 0;

    assembler = asm_create(filename);
    if (assembler == NULL)
        return (EXIT_FAILURE);
    status = asm_fill(assembler);
    if (status == EXIT_FAILURE)
        return (EXIT_FAILURE);
    status = asm_write(assembler);
    asm_destroy(assembler);
    return (status);
}