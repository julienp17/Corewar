/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** mem_manipulation
*/

#include "vm.h"
#include "op.h"

int get_mem_value(char mem[MEM_SIZE], int address)
{
    int value = 0;

    for (int i = 0 ; i < REG_SIZE ; i++) {
        value = (value << 8) + mem[address];
        address = (address + 1) % MEM_SIZE;
    }
    return (value);
}

void set_mem_value(char mem[MEM_SIZE], int address, int value)
{
    for (int i = 0 ; i < REG_SIZE ; i++) {
        mem[address] = (value >> (8 * (3 - i))) & 0xFF;
        address = (address + 1) % MEM_SIZE;
    }
}