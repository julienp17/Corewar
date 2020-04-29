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
    ssize_t total_bytes_written = 0;
    ssize_t bytes_written = 1;

    if (encode_header(fd, instructions) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    my_strarr_rotate(instructions, 0);
    if (my_str_beg(instructions[0], COMMENT_CMD_STRING))
        my_strarr_rotate(instructions, 0);
    for (uint i = 0 ; bytes_written > 0 && instructions[i] ; i++) {
        bytes_written = encode_instruction(fd, instructions[i]);
        total_bytes_written += bytes_written;
    }
    if (bytes_written <= 0)
        return (EXIT_FAILURE);
    if (lseek(fd, sizeof(int) * 2 + sizeof(char) * PROG_NAME_LENGTH, SEEK_SET) < 0){
        my_puterr("Coudln't lseek back to program size.\n");
        return (EXIT_FAILURE);
    }
    total_bytes_written = swap_int32(total_bytes_written);
    if (write(fd, &(total_bytes_written), sizeof(int)) < 0) {
        perror("write");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}