/*
** EPITECH PROJECT, 2020
** asm
** File description:
** instruction
*/

#ifndef INSTRUCTION_H_
    #define INSTRUCTION_H_

    #include <stdbool.h>
    #include <sys/types.h>
    #include "op.h"

    typedef unsigned char uchar;

    typedef struct instruction_arg {
        uchar type;
        int value;
        uchar size;
    } arg_t;

    typedef struct instruction {
        char *label;
        op_t op;
        uchar coding_byte;
        ssize_t size;
        arg_t args[MAX_ARGS_NUMBER];
        ssize_t offset;
    } instruction_t;

    instruction_t *instruction_create(char const *line);
    void instruction_destroy(instruction_t *instruction);

    ssize_t instruction_write(instruction_t *instruction, int fd);
    bool instruction_is_label(instruction_t const *instruction);
#endif