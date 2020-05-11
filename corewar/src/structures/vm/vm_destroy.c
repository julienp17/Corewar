/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Free a vm structure
*/

#include <stdlib.h>
#include "virtual_machine.h"

void vm_destroy(vm_t *vm)
{
    free(vm);
}