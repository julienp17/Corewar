/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** Returns a newly allocated assembler structure
*/

#include <stdlib.h>
#include "instruction.h"
#include "my.h"
#include "asm.h"

static void fill_instruction(instruction_t *instruction, char **tokens);

instruction_t *instruction_create(char const *line)
{
    instruction_t *instruction = NULL;
    char **tokens = NULL;

    instruction = malloc(sizeof(instruction_t));
    if (instruction == NULL) {
        my_puterr("Couldn't allocate memory for instruction.\n");
        return (NULL);
    }
    instruction->label = NULL;
    tokens = parse_instruction(line);
    fill_instruction(instruction, tokens);
    for (int i = 0 ; i < MAX_ARGS_NUMBER ; i++)
        instruction->args[i] = (arg_t) {0, 0, 0};
    instruction->size = instruction_get_size(line);
    instruction->offset = 0;
    my_free_str_array(tokens);
    return (instruction);
}

static void fill_instruction(instruction_t *instruction, char **tokens)
{
    if (my_str_ends_char(tokens[0], LABEL_CHAR)) {
        tokens[0][my_strlen(tokens[0]) - 1] = '\0';
        instruction->label = my_strdup(tokens[0]);
        my_strarr_rotate(tokens, 0);
    }
    if (tokens[0] != NULL) {
        instruction->op = op_get_by_name(tokens[0]);
        instruction->coding_byte = instruction_get_coding_byte(tokens + 1);
    } else {
        instruction->op = (op_t) {0, 0, {0}, 0, 0, 0};
        instruction->coding_byte = 0;
    }
}