/*
** EPITECH PROJECT, 2020
** Corewar Assembler
** File description:
** Encode instructions to a file
*/

#include "asm.h"
#include "my.h"

int encode_to_file(char const *output_filename, char **instructions)
{
    int fd = 0;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    int status = EXIT_SUCCESS;

    fd = open(output_filename, O_CREAT | O_TRUNC | O_WRONLY, mode);
    if (fd < 0) {
        my_puterr("Error opening file.\n");
        return (EXIT_FAILURE);
    }
    status = encode(fd, instructions);
    if (close(fd) < 0) {
        my_puterr("Error closing file.\n");
        return (EXIT_FAILURE);
    }
    return (status);
}

int encode(int fd, char **instructions)
{
    int status = EXIT_SUCCESS;

    status = encode_header(fd, instructions);
    for (uint i = 0 ; status == EXIT_SUCCESS && instructions[i] ; i++)
        status = encode_instruction(fd, instructions[i]);
    return (status);
}