/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** Fill an instruction value
*/

#include "asm.h"
#include "my.h"

static arg_t get_argument(char *arg_str, instruction_t *instruction,
                                    instruction_t **instructions);
static bool label_arg_is_incorrect(arg_t arg, char const *arg_str);

int asm_fill_instruction_value(asm_t *asb, char const *line)
{
    instruction_t *instruction = NULL;
    char **args = NULL;

    instruction = asb->instructions[asb->nb_instructions++];
    if (instruction->label != NULL && instruction->op.mnemonique == 0)
        return (EXIT_SUCCESS);
    args = parse_instruction(line);
    if (my_str_ends_char(args[0], LABEL_CHAR))
        my_strarr_rotate(args, 0);
    my_strarr_rotate(args, 0);
    for (int i = 0 ; i < instruction->op.nbr_args ; i++) {
        instruction->args[i] = get_argument(args[i], instruction,
                                            asb->instructions);
        if (label_arg_is_incorrect(instruction->args[i], args[i])) {
            asm_puterr(asb, "Undefined label");
            return (EXIT_FAILURE);
        }
    }
    my_free_str_array(args);
    return (EXIT_SUCCESS);
}

static arg_t get_argument(char *arg_str, instruction_t *instruction,
                                    instruction_t **instructions)
{
    arg_t arg = (arg_t) {0, 0, 0};

    arg.type  = argument_get_type(arg_str);
    arg.size  = argument_get_size(arg_str, instruction->op);
    arg.value = argument_get_value(arg_str, instruction, instructions);
    return (arg);
}

static bool label_arg_is_incorrect(arg_t arg, char const *arg_str)
{
    return (
        my_str_contains_char(arg_str, LABEL_CHAR)
        && arg.value == -1
    );
}