/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Argument structure header file
*/

#ifndef ARGUMENT_H_
    #define ARGUMENT_H_

    #include <stdbool.h>
    #include "op.h"

    typedef struct argument {
        int value;
        char size;
        char type;
    } arg_t;

    bool arguments_are_correct(op_t op, arg_t args[MAX_ARGS_NUMBER]);
    bool argument_is_index(op_t op);
    char argument_get_size(char const arg_type, op_t op);
#endif