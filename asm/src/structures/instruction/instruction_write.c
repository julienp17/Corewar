/*
** EPITECH PROJECT, 2020
** asm
** File description:
** instruction_write
*/

#include <unistd.h>
#include "instruction.h"
#include "asm.h"
#include "my.h"

static ssize_t write_args(instruction_t *instruction, int fd);

ssize_t instruction_write(instruction_t *instruction, int fd)
{
    ssize_t bytes_written = 0;

    if (instruction_is_label(instruction))
        return (0);
    bytes_written = write(fd, &(instruction->op.code), sizeof(char));
    if (bytes_written < 0) {
        my_puterr("Error writing instruction op code.\n");
        return (bytes_written);
    }
    if (op_has_coding_byte(instruction->op)) {
        bytes_written = write(fd, &(instruction->coding_byte), sizeof(char));
        if (bytes_written < 0) {
            my_puterr("Error writing instruction coding byte.\n");
            return (bytes_written);
        }
    }
    bytes_written = write_args(instruction, fd);
    return (bytes_written);
}

static ssize_t write_args(instruction_t *instruction, int fd)
{
    ssize_t total_bytes_written = 0;
    ssize_t bytes_written = 0;

    for (int i = 0 ; i < instruction->op.nbr_args ; i++) {
        bytes_written = write(fd, &(instruction->args[i].value),
                                    instruction->args[i].size);
        if (bytes_written < 0) {
            my_puterr("Error writing instruction argument.\n");
            return (bytes_written);
        }
        total_bytes_written += bytes_written;
    }
    return (total_bytes_written);
}