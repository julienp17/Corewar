/*
** EPITECH PROJECT, 2020
** Corewar Assembler
** File description:
** Assemble an assembler file
*/

#include "asm.h"
#include "file_control.h"
#include "my.h"

static int encode(char const *output_filename, char **instructions);

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
    status = encode(output_filename, instructions);
    free(output_filename);
    // my_free_str_array(instructions);
    return (status);
}

static int encode(char const *output_filename, char **instructions)
{
    int fd = 0;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    int status = EXIT_SUCCESS;

    fd = open(output_filename, O_CREAT | O_TRUNC | O_WRONLY, mode);
    if (fd < 0) {
        my_puterr("Error opening file.\n");
        return (EXIT_FAILURE);
    }
    status = encode_header(fd, instructions);
    for (uint i = 0 ; status == EXIT_SUCCESS && instructions[i] ; i++)
        status = encode_instruction(fd, instructions[i]);
    if (close(fd) < 0) {
        my_puterr("Error closing file.\n");
        return (EXIT_FAILURE);
    }
    return (status);
}