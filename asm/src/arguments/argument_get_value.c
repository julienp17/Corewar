/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** Returns the argument value
*/

#include "asm.h"
#include "my.h"

int get_label_value(char const *arg, instruction_t *instruction,
                                instruction_t **instructions);

int argument_get_value(char const *arg, instruction_t *instruction,
                        instruction_t **instructions)
{
    int arg_type = 0;
    int value = 0;

    arg_type = argument_get_type(arg);
    if (arg_type == T_REG) {
        value = (char)my_atoi(arg + 1);
    } else if (arg_type == T_IND || arg_type == T_LAB) {
        if (arg_type == T_IND) {
            value = (short int)my_atoi(arg);
            value = (short int)swap_int16(value);
        } else {
            value = get_label_value(arg, instruction, instructions);
        }
    } else if (arg_type == T_DIR) {
        if (argument_is_index(instruction->op))
            return (argument_get_value(arg + 1, instruction, instructions));
        value = my_atoi(arg + 1);
        value = swap_int32(value);
    }
    return (value);
}

int get_label_value(char const *arg, instruction_t *instruction,
                                instruction_t **instructions)
{
    int value = 0;
    instruction_t *label = NULL;
    char *arg_cpy = NULL;

    arg_cpy = my_strdup(arg);
    my_str_rotate(arg_cpy, 0);
    for (uint i = 0 ; instructions[i] && label == NULL ; i++)
        if (instructions[i]->label &&
                                my_strcmp(instructions[i]->label, arg_cpy) == 0)
            label = instructions[i];
    if (label == NULL)
        value = -1;
    else
        value = swap_int16(label->offset - instruction->offset);
    free(arg_cpy);
    return (value);
}