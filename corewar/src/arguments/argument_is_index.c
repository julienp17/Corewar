/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** Returns true if the argument is an index, false otherwise
*/

#include <stdbool.h>
#include "op.h"
#include "my.h"

bool argument_is_index(op_t op)
{
    return (
        my_str_contains(op.comment, "index")
        || (op.nbr_args == 1 && op.type[0] == T_DIR
            && my_strcmp(op.mnemonique, "live") != 0)
    );
}