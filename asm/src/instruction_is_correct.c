/*
** EPITECH PROJECT, 2020
** Corewar Assembler
** File description:
** Checks if an instruction is correct
*/

#include "asm.h"
#include "my.h"

static bool label_is_correct(char const *label_str);
static bool arguments_are_correct(op_t op, char **args);

bool instruction_is_correct(char **tokens)
{
    int i = 0;
    op_t op;

    if (my_str_ends_char(tokens[0], LABEL_CHAR)) {
        i++;
        if (label_is_correct(tokens[0]) == false)
            return (false);
    }
    op = get_op_by_name(tokens[i]);
    if (op.mnemonique == 0) {
        my_puterr(tokens[i]);
        my_puterr(" : Invalid instruction.\n");
        return (false);
    }
    i++;
    if (arguments_are_correct(op, tokens + i) == false)
        return (false);
    return (true);
}

static bool label_is_correct(char const *label)
{
    if (label[0] == LABEL_CHAR) {
        my_puterr("Label can't be empty\n");
        return (false);
    }
    for (uint i = 0 ; label[i] != LABEL_CHAR && label[i] ; i++) {
        if (my_str_contains_char(LABEL_CHARS, label[i]) == false) {
            my_puterr(label);
            my_puterr(" : Invalid label name\n");
            return (false);
        }
    }
    return (true);
}

static bool arguments_are_correct(op_t op, char **args)
{
    int arg_type = 0;

    if ((char)my_strarr_len(args) != op.nbr_args) {
        my_puterr("Invalid number of arguments for '");
        my_puterr(op.mnemonique);
        my_puterr("' instruction\n");
        return (false);
    }
    for (uint i = 0 ; args[i] ; i++) {
        arg_type = get_argument_type(args[i]);
        if ((arg_type & op.type[i]) == 0) {
            my_puterr(args[i]);
            my_puterr(" : Invalid argument type for '");
            my_puterr(op.mnemonique);
            my_puterr("' instruction.\n");
            return (false);
        }
    }
    return (true);
}