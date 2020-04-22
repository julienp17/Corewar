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
    char **instructions = NULL;
    char *output_filename = NULL;
    int status = 0;

    instructions = parse_instructions_from_file(filename);
    if (instructions == NULL)
        return (EXIT_FAILURE);
    output_filename = get_output_filename(filename);
    if (output_filename == NULL)
        return (EXIT_FAILURE);
    status = encode_to_file(output_filename, instructions);
    free(output_filename);
    my_free_str_array(instructions);
    return (status);
}