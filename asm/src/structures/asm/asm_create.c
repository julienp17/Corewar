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
    assembler->nb_instructions = 0;
    assembler->instructions = NULL;
    return (assembler);
}

static header_t header_create(void)
{
    header_t header;

    header.magic = swap_int32(COREWAR_EXEC_MAGIC);
    for (int i = 0 ; i < PROG_NAME_LENGTH ; i++)
        header.prog_name[i] = 0;
    header.prog_size = 0;
    for (int i = 0 ; i < COMMENT_LENGTH ; i++)
        header.comment[i] = 0;
    return (header);
}