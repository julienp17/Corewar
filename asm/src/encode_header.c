/*
** EPITECH PROJECT, 2020
** asm
** File description:
** encode_header
*/

#include "asm.h"
#include "my.h"

static int encode_exec_magic(int fd);
static int encode_program_name(int fd, char const *program_name_line);
static int encode_program_comment(int fd, char const *program_comment_line);

int encode_header(int fd, char **instructions)
{
    if (encode_exec_magic(fd) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (encode_program_name(fd, instructions[0]) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (encode_program_comment(fd, instructions[1]) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    my_strarr_rotate(instructions, 0);
    if (my_str_beg(instructions[0], COMMENT_CMD_STRING))
        my_strarr_rotate(instructions, 0);
    return (EXIT_SUCCESS);
}

static int encode_exec_magic(int fd)
{
    int exec_magic = 0;

    exec_magic = swap_int32(COREWAR_EXEC_MAGIC);
    if (write(fd, &(exec_magic), sizeof(exec_magic)) < 0) {
        my_puterr("Error writing corewar exec magic.\n");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

static int encode_program_name(int fd, char const *program_name_line)
{
    char program_name[PROG_NAME_LENGTH] = "";
    char *delim = NULL;

    if (my_str_beg(program_name_line, NAME_CMD_STRING) == false) {
        my_puterr("'.name' wasn't found on the first line of the program.\n");
        return (EXIT_FAILURE);
    }
    delim = my_str_delim(program_name_line, '"', '"');
    if (delim == NULL) {
        my_puterr("No program name specified.\n");
        return (EXIT_FAILURE);
    }
    my_strcpy(program_name, delim);
    if (write(fd, program_name, PROG_NAME_LENGTH) < 0) {
        my_puterr("Error writing program name.\n");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

static int encode_program_comment(int fd, char const *program_comment_line)
{
    char program_comment[COMMENT_LENGTH] = "";
    char *delim = NULL;

    if (my_str_beg(program_comment_line, COMMENT_CMD_STRING)) {
        delim = my_str_delim(program_comment_line, '"', '"');
        if (delim == NULL) {
            my_puterr("No comment specified.\n");
            return (EXIT_FAILURE);
        }
        my_strcpy(program_comment, delim);
    } else {
        my_puterr("Warning : No comment specified.\n");
    }
    if (write(fd, program_comment, COMMENT_LENGTH) < 0) {
        my_puterr("Error writing program comment.\n");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}