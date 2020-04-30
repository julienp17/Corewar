/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** Unit tests for swap_endianess
*/

#include <criterion/criterion.h>
#include "asm.h"

Test(swap_endianess, corewar_exec_magic)
{
    int32_t nb = 0x00ea83f3;
    int32_t expected = 0xf383ea00;

    nb = swap_int32(nb);
    cr_assert_eq(nb, expected);
}

Test(swap_endianess, deadbeef)
{
    int32_t nb = 0xdeadbeef;
    int32_t expected = 0xefbeadde;

    nb = swap_int32(nb);
    cr_assert_eq(nb, expected);
}

Test(swap_endianess, int32_01)
{
    int32_t nb = 0x00000001;
    int32_t expected = 0x01000000;

    nb = swap_int32(nb);
    cr_assert_eq(nb, expected);
}

Test(swap_endianess, int16_01)
{
    int16_t nb = 0x0001;
    int16_t expected = 0x0100;

    nb = swap_int16(nb);
    cr_assert_eq(nb, expected);
}

Test(swap_endianess, int16_fefe)
{
    int16_t nb = 0xfefe;
    int16_t expected = 0xfefe;

    nb = swap_int16(nb);
    cr_assert_eq(nb, expected);
}

Test(swap_endianess, int16_abcd)
{
    int16_t nb = 0xabcd;
    int16_t expected = 0xcdab;

    nb = swap_int16(nb);
    cr_assert_eq(nb, expected);
}