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

    #define NO_CB_MASK              0b10000000

    typedef struct instruction {
        op_t op;
        arg_t args[MAX_ARGS_NUMBER];
    } instruction_t;

    instruction_t *instruction_create(void);
    void instruction_reset(instruction_t *instruction);

#endif