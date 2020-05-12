/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Return the correct operation based on op.code
*/

#include "operation.h"

int (*operation_get(int const code))(vm_t *, champion_t *)
{
    int (*operation)(vm_t *, champion_t *) = NULL;
    operation_t operations[] = {
        {1, &live}, {2, &ld}, {9, &zjmp}, {11, &sti},
        {-1, 0}
    };

    for (unsigned int i = 0 ; operations[i].code > 0 && operation == NULL ; i++)
        if (code == operations[i].code)
            operation = operations[i].function;
    return (operation);
}