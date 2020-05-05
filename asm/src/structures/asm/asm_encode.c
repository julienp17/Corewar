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
static int asm_encode_to_file(asm_t *asb, char const *output_filename);
static int asm_encode_to_fd(asm_t *asb, int fd);

int asm_encode(asm_t *asb)
{
    int status = 0;
    char *output_filename = NULL;

    output_filename = get_output_filename(asb->input_filename);
    if (output_filename == NULL)
        return (EXIT_FAILURE);
    status = asm_encode_to_file(asb, output_filename);
    free(output_filename);
    return (status);
}

static int asm_encode_to_file(asm_t *asb, char const *output_filename)
{
    int fd = 0;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    int status = EXIT_SUCCESS;

    fd = open(output_filename, O_CREAT | O_TRUNC | O_WRONLY, mode);
    if (fd < 0) {
        my_puterr("Error opening file.\n");
        return (EXIT_FAILURE);
    }
    status = asm_encode_to_fd(asb, fd);
    if (close(fd) < 0) {
        my_puterr("Error closing file.\n");
        status = EXIT_FAILURE;
    }
    return (status);
}

static int asm_encode_to_fd(asm_t *asb, int fd)
{
    ssize_t bytes_written = 0;

    if (asm_encode_header(fd, &(asb->header)) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    for (uint i = 0 ; i < asb->nb_instructions ; i++) {
        bytes_written = instruction_write(asb->instructions[i], fd);
        if (bytes_written < 0)
            return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

static char *get_output_filename(char const *filename)
{
    char *output_filename = NULL;

    output_filename = my_strdup(filename);
    output_filename = get_pretty_filename(output_filename);
    output_filename = my_strdupcat(output_filename, COR_EXT);
    return (output_filename);
}