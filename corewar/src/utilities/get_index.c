/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Returns an index that is certainly in the bounds of the vm
*/

#include "op.h"

int get_index(int const pc, int const value, int flag)
{
    int index = 0;

    if (flag == IDX_MOD && value > 0)
        index = pc + value % IDX_MOD;
    else
        index = pc + value;
    if (index < 0)
        index += MEM_SIZE;
    else if (index > MEM_SIZE)
        index %= MEM_SIZE;
    return (index);
}