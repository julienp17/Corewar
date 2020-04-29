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
static bool argument_is_correct(op_t op, char const *arg, uint i);

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
        my_eprintf("%s : Invalid instruction.\n", tokens[i]);
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
            my_eprintf("%s : Invalid label name\n", label);
            return (false);
        }
    }
    return (true);
}

static bool arguments_are_correct(op_t op, char **args)
{
    char *cmd = NULL;

    cmd = op.mnemonique;
    if (my_strarr_len(args) != (unsigned int)(op.nbr_args)) {
        my_eprintf("Invalid number of arguments for '%s' instruction.\n", cmd);
        return (false);
    }
    for (uint i = 0 ; args[i] ; i++)
        if (argument_is_correct(op, args[i], i) == false)
            return (false);
    return (true);
}

static bool argument_is_correct(op_t op, char const *arg, uint i)
{
    char *cmd = NULL;
    int arg_type = 0;
    int value = 0;

    cmd = op.mnemonique;
    arg_type = get_argument_type(arg);
    if (arg_type == T_REG) {
        value = my_atoi(arg + 1);
        if (value < 1 || value > REG_NUMBER) {
            my_eprintf("%s : Invalid register value.\n", arg);
            return (false);
        }
    }
    if ((arg_type & op.type[i]) == 0) {
        my_eprintf("%s : Invalid argument type for '%s'\n", arg, cmd);
        return (false);
    }
    return (true);
}