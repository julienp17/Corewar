/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Unit test for get_index
*/

#include <criterion/criterion.h>
#include "corewar.h"

Test(get_index, normal_index_forward)
{
    int pc = 12;
    int value = 14;
    int index = 0;
    int const expected = pc + value;

    index = get_index(pc, value);
    cr_assert_eq(index, expected);
}

Test(get_index, normal_index_backward)
{
    int pc = 12;
    int value = -8;
    int index = 0;
    int const expected = pc + value;

    index = get_index(pc, value);
    cr_assert_eq(index, expected);
}

Test(get_index, value_eq_zero)
{
    int pc = 18;
    int value = 0;
    int index = 0;
    int const expected = pc;

    index = get_index(pc, value);
    cr_assert_eq(index, expected);
}

Test(get_index, value_greater_than_idx_mod)
{
    int pc = 0;
    int value = 518;
    int index = 0;
    int const expected = value % IDX_MOD;

    index = get_index(pc, value);
    cr_assert_eq(index, expected);
}

Test(get_index, pc_plus_value_greater_than_mem)
{
    int pc = MEM_SIZE - 4;
    int value = 6;
    int index = 0;
    int const expected = 2;

    index = get_index(pc, value);
    cr_assert_eq(index, expected);
}

Test(get_index, value_negative_mem)
{
    int pc = 2;
    int value = -6;
    int index = 0;
    int const expected = MEM_SIZE - 4;

    index = get_index(pc, value);
    cr_assert_eq(index, expected);
}