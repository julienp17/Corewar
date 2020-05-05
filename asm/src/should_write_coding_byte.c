/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** Returns true if the coding byte should be written, false otherwise
*/

#include <stdbool.h>
#include "op.h"

bool should_write_coding_byte(op_t op)
{
    return (op.nbr_args != 1 || op.type[0] != T_DIR);
}