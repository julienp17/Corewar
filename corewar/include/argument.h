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

    bool argument_is_index(op_t op);
#endif