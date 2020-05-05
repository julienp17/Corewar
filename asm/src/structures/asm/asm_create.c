/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** Returns a newly allocated assembler structure
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"

static header_t header_create(void);

asm_t *asm_create(char const *filename)
{
    asm_t *assembler = NULL;

    assembler = malloc(sizeof(asm_t));
    if (assembler == NULL) {
        my_puterr("Couldn't allocate memory for assembler structure.\n");
        return (NULL);
    }
    assembler->input_filename = my_strdup(filename);
    assembler->lines = parse_instructions_from_file(filename);
    assembler->header = header_create();
    assembler->line = 0;
    return (assembler);
}

static header_t header_create(void)
{
    header_t header;

    header.magic = COREWAR_EXEC_MAGIC;
    my_strcpy(header.prog_name, "");
    header.prog_size = 0;
    my_strcpy(header.comment, "");
    return (header);
}