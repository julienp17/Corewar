/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** instructions
*/

#include "op.h"

#ifndef INSTRUCTIONS_H_
#define INSTRUCTIONS_H_

#define HEADER_SIZE sizeof(int)+(sizeof(char)*PROG_NAME_LENGTH)+(sizeof(int))+(sizeof(char) * COMMENT_LENGTH)
#define R_INST 1
#define R_CODE 2
#define R_PARAM 3

typedef struct s_parameters_prog {
    int value;
    int type;
}params_t;

typedef struct s_infos_instructions {
    op_t op;
    params_t **params;
    struct s_infos_instructions *next;
}instr_t;

#endif /* !INSTRUCTIONS_H_ */
