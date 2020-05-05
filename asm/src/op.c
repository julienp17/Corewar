/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** op
*/

#include "asm.h"
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

op_t get_op_by_name(char const *name)
{
    unsigned int i = 0;

    for (i = 0 ; op_tab[i].mnemonique != 0 ; i++)
        if (my_strcmp(op_tab[i].mnemonique, name) == 0)
            return (op_tab[i]);
    return (op_tab[i]);
}

bool op_has_coding_byte(op_t op)
{
    return (op.nbr_args != 1 || op.type[0] != T_DIR);
}

int get_argument_type(char const *arg)
{
    if (arg[0] == REGISTER_CHAR)
        return (T_REG);
    if (arg[0] == DIRECT_CHAR)
        return (T_DIR);
    if (arg[0] == LABEL_CHAR)
        return (T_LAB);
    if (my_char_is_digit(arg[0]))
        return (T_IND);
    return (0);
}

int get_argument_size(char const *arg, op_t op)
{
    int arg_type = 0;

    arg_type = get_argument_type(arg);
    if (arg_type == T_REG)
        return (1);
    if (arg_type == T_IND || arg_type == T_LAB)
        return (IND_SIZE);
    if (arg_type == T_DIR)
        return (arg_is_index(op) ? IND_SIZE : DIR_SIZE);
    return (-1);
}

int get_argument_value(char *arg, instruction_t *instruction, instruction_t **instructions)
{
    int arg_type = 0;
    int value = 0;
    instruction_t *label = NULL;

    arg_type = get_argument_type(arg);
    if (arg_type == T_REG) {
        value = (char)my_atoi(arg + 1);
    } else if (arg_type == T_IND || arg_type == T_LAB) {
        if (arg_type == T_IND) {
            value = (short int)my_atoi(arg);
            value = (short int)swap_int16(value);
        } else {
            my_str_rotate(arg, 0);
            for (uint i = 0 ; instructions[i] && label == NULL ; i++)
                if (instructions[i]->label && my_strcmp(instructions[i]->label, arg) == 0)
                    label = instructions[i];
            if (label == NULL) {
                my_eprintf("%s : unknown label.\n", arg);
                return (-1);
            }
            value = swap_int16(label->offset - instruction->offset);
        }
    } else if (arg_type == T_DIR) {
        if (arg_is_index(instruction->op))
            return (get_argument_value(arg + 1, instruction, instructions));
        value = my_atoi(arg + 1);
        value = swap_int32(value);
    }
    return (value);
}

bool arg_is_index(op_t op)
{
    return (
        my_str_contains(op.comment, "index")
        || (op.nbr_args == 1 && op.type[0] == T_DIR
            && my_strcmp(op.mnemonique, "live") != 0)
    );
}