/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** Returns a newly allocated assembler structure
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"

asm_t *asm_create(char const *filename)
{
    asm_t *assembler = NULL;

    assembler = malloc(sizeof(asm_t));
    if (assembler == NULL) {
        my_puterr("Couldn't allocate memory for assembler structure.\n");
        return (NULL);
    }
    assembler->input_filename = my_strdup(filename);
    assembler->file_lines = parse_instructions_from_file(filename);
    assembler->line = 0;
    return (assembler);
}