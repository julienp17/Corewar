/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Dump the memory of the vm
*/

#include <stdio.h>
#include "vm.h"

void vm_dump_mem(vm_t *vm)
{
    int const offset = 0x20;

    for (int i = 0 ; i < MEM_SIZE ; i += offset) {
        printf("%-4X : ", i);
        for (int j = 0 ; j < offset ; j++)
            printf(" %02X", vm->mem[i + j]);
        printf("\n");
    }
}