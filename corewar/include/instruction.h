/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Instruction structure header file
*/

#ifndef INSTRUCTIONS_H_
    #define INSTRUCTIONS_H_

    #include "argument.h"
    #include "op.h"

    typedef struct instruction {
        op_t op;
        arg_t args[MAX_ARGS_NUMBER];
        struct instruction *next;
    } instruction_t;
    typedef struct instruction instr_t;

    instruction_t *instruction_create(void);

    instr_t *get_prog(int fd);

#endif