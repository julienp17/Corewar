/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** op
*/

#include "op.h"
#include "my.h"

op_t op_tab[] = {
    {"live", 1, {T_DIR}, 1, 10, "alive"},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load"},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store"},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition"},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction"},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
    "et (and  r1, r2, r3   r1&r2 -> r3"},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
    "ou  (or   r1, r2, r3   r1 | r2 -> r3"},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
    "ou (xor  r1, r2, r3   r1^r2 -> r3"},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero"},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
    "load index"},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
    "store index"},
    {"fork", 1, {T_DIR}, 12, 800, "fork"},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load"},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
    "long load index"},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork"},
    {"aff", 1, {T_REG}, 16, 2, "aff"},
    {0, 0, {0}, 0, 0, 0}
};

bool op_is_null(op_t op)
{
    return (
        op.mnemonique == 0
        && op.nbr_args == 0
        && op.type[0] == 0
        && op.code == 0
        && op.nbr_cycles == 0
        && op.comment == 0
    );
}

op_t op_get_by_code(unsigned char code)
{
    unsigned int i = 0;

    for (i = 0 ; op_tab[i].code != 0 ; i++)
        if (op_tab[i].code == code)
            return (op_tab[i]);
    return (op_tab[i]);
}

bool op_has_coding_byte(op_t op)
{
    return (op.nbr_args != 1 || op.type[0] != T_DIR);
}

bool op_modifies_carry(op_t op)
{
    int const modifies_carry_opcodes[] = {
        0x04, 0x05, 0x06, 0x07, 0x08, 0x0A, 0x0D, 0x0E, -1
    };

    for (unsigned int i = 0 ; modifies_carry_opcodes[i] > 0 ; i++)
        if (op.code == modifies_carry_opcodes[i])
            return (true);
    return (false);
}