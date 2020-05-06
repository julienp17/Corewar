/*
** EPITECH PROJECT, 2020
** asm
** File description:
** asm_encode_header
*/

#include "asm.h"
#include "my.h"

static int encode_exec_magic(int fd, int exec_magic);
static int encode_program_name(int fd, char program_name[PROG_NAME_LENGTH]);
static int encode_program_size(int fd, int size);
static int encode_program_comment(int fd, char comment[COMMENT_LENGTH]);

int asm_encode_header(int fd, header_t *header)
{
    int offset = 0;

    if (encode_exec_magic(fd, header->magic) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (encode_program_name(fd, header->prog_name) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (encode_program_size(fd, header->prog_size) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (encode_program_comment(fd, header->comment) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (write(fd, &(offset), sizeof(offset)) < 0) {
        my_puterr("Error writing program header offset.\n");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

static int encode_exec_magic(int fd, int exec_magic)
{
    if (write(fd, &(exec_magic), sizeof(exec_magic)) < 0) {
        my_puterr("Error writing corewar exec magic.\n");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

static int encode_program_name(int fd, char program_name[PROG_NAME_LENGTH])
{
    if (write(fd, program_name, PROG_NAME_LENGTH) < 0) {
        my_puterr("Error writing program name.\n");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

static int encode_program_size(int fd, int program_size)
{
    int offset = 0;

    if (write(fd, &(offset), sizeof(offset)) < 0) {
        my_puterr("Error writing program offset.\n");
        return (EXIT_FAILURE);
    }
    if (write(fd, &(program_size), sizeof(program_size)) < 0) {
        my_puterr("Error writing program unknown nb.\n");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

static int encode_program_comment(int fd, char comment[COMMENT_LENGTH])
{
    if (write(fd, comment, COMMENT_LENGTH) < 0) {
        my_puterr("Error writing program comment.\n");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}