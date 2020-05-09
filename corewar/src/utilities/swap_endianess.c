/*
** EPITECH PROJECT, 2020
** Corewar Assembler
** File description:
** Swap the endianess of integers
*/

#include <stdint.h>

int16_t swap_int16(int16_t val)
{
    return (val << 8) | ((val >> 8) & 0xFF);
}

int32_t swap_int32(int32_t val)
{
    val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0x00FF00FF);
    return (val << 16) | ((val >> 16) & 0xFFFF);
}