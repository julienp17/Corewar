/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Checks if the arguments are correct
*/

#include <stdbool.h>
#include "op.h"
#include "argument.h"

bool arguments_are_correct(op_t op, arg_t args[MAX_ARGS_NUMBER])
{
    int nb_args = 0;

    for (int i = 0 ; i < MAX_ARGS_NUMBER ; i++)
        if (args[i].type != 0)
            nb_args++;
    if (nb_args != op.nbr_args)
        return (false);
    for (int i = 0 ; i < op.nbr_args ; i++) {
        if ((args[i].type & op.type[i]) == 0)
            return (false);
        if (args[i].type == T_REG)
            if (args[i].value < 1 || args[i].value > REG_NUMBER)
                return (false);
    }
    return (true);
}