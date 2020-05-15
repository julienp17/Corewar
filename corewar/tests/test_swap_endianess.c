/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** test_swap_endianess
*/

#include <criterion/criterion.h>
#include "corewar.h"

Test(swap_int16, test_swap_int16_simple_numbers)
{
    int expected = 0x32f4;
    int given = 0xf432;

    cr_assert_eq(swap_int16(given), expected);
}

Test(swap_int32, test_swap_int32_simple_numbers)
{
    int expected = 0xfa32c201;
    int given = 0x01c232fa;

    cr_assert_eq(swap_int32(given), expected);
}