/*
** EPITECH PROJECT, 2020
** Corewar Assembler
** File description:
** Checks if an instruction is correct
*/

#include "asm.h"
#include "my.h"

static bool label_is_correct(asm_t *asb, char const *label_str);
static bool arguments_are_correct(asm_t *asb, op_t op, char **args);
static bool argument_is_correct(asm_t *asb, op_t op, char const *arg, uint i);

bool instruction_is_correct(asm_t *asb, char const *instruction)
{
    op_t op;
    char **tokens = NULL;

    tokens = parse_instruction(instruction);
    if (my_str_ends_char(tokens[0], LABEL_CHAR)) {
        if (label_is_correct(asb, tokens[0]) == false)
            return (false);
        my_strarr_rotate(tokens, 0);
        if (tokens[0] == NULL)
            return (true);
    }
    op = op_get_by_name(tokens[0]);
    if (op.mnemonique == 0) {
        asm_puterr(asb, "Invalid instruction");
        return (false);
    }
    if (arguments_are_correct(asb, op, tokens + 1) == false)
        return (false);
    my_free_str_array(tokens);
    return (true);
}

static bool label_is_correct(asm_t *asb, char const *label)
{
    if (label[0] == LABEL_CHAR) {
        asm_puterr(asb, "Empty label");
        return (false);
    }
    for (uint i = 0 ; label[i] != LABEL_CHAR && label[i] ; i++) {
        if (my_str_contains_char(LABEL_CHARS, label[i]) == false) {
            asm_puterr(asb, "Invalid label name");
            return (false);
        }
    }
    return (true);
}

static bool arguments_are_correct(asm_t *asb, op_t op, char **args)
{
    if (my_strarr_len(args) != (unsigned int)(op.nbr_args)) {
        asm_puterr(asb, "Too many arguments given to the instruction");
        return (false);
    }
    for (uint i = 0 ; args[i] ; i++)
        if (argument_is_correct(asb, op, args[i], i) == false)
            return (false);
    return (true);
}

static bool argument_is_correct(asm_t *asb, op_t op, char const *arg, uint i)
{
    int arg_type = 0;
    int value = 0;

    arg_type = argument_get_type(arg);
    if (arg_type == 0 || (arg_type & op.type[i]) == 0) {
        asm_puterr(asb, "The argument given to the instruction is invalid");
        return (false);
    }
    if (arg_type == T_REG) {
        value = my_atoi(arg + 1);
        if (value < 1 || value > REG_NUMBER) {
            asm_puterr(asb, "Invalid register number");
            return (false);
        }
    }
    return (true);
}