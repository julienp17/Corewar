/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Dump the memory of the vm
*/

#include "vm.h"
#include "my.h"

void vm_dump(vm_t *vm)
{
    int const offset = 0x20;

    for (int i = 0 ; i < MEM_SIZE ; i += offset) {
        my_printf("%-4X : ", i);
        for (int j = 0 ; j < offset ; j++)
            my_printf("%02X ", (unsigned char)vm->mem[i + j]);
        my_printf("\n");
    }
}