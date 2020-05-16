/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Return the correct operation based on op.code
*/

#include "operation.h"

int (*operation_get(int const code))(vm_t *, proc_t *)
{
    int (*operation)(vm_t *, proc_t *) = NULL;
    operation_t operations[] = {
        {1, &live}, {2, &ld}, {3, &st}, {4, &add}, {5, &sub},
        {6, &and}, {7, &or}, {8, &xor}, {9, &zjmp}, {10, &ldi}, {11, &sti},
        {12, &proc_fork}, {13, &lld}, {14, &lldi}, {15, &proc_lfork},
        {16, &aff}, {-1, 0}
    };

    for (unsigned int i = 0 ; operations[i].code > 0 && operation == NULL ; i++)
        if (code == operations[i].code)
            operation = operations[i].function;
    return (operation);
}