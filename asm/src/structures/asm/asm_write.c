/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** Write the encoded data to a file
*/

#include "asm.h"
#include "my.h"
#include "file_control.h"

static char *get_output_filename(char const *filename);

int asm_write(asm_t *assembler)
{
    int status = 0;
    char *output_filename = NULL;

    (void)assembler;
    output_filename = get_output_filename(assembler->input_filename);
    free(output_filename);
    return (status);
}

static char *get_output_filename(char const *filename)
{
    char *output_filename = NULL;

    output_filename = my_strdup(filename);
    output_filename = get_pretty_filename(output_filename);
    output_filename = my_strdupcat(output_filename, COR_EXT);
    return (output_filename);
}