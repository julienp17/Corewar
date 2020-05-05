/*
** EPITECH PROJECT, 2020
** asm
** File description:
** asm_allocate_instructions
*/

#include "asm.h"
#include "my.h"

static int allocate_instructions(asm_t *asb);
static bool is_not_instruction(char const *line);

int asm_fill_instructions_meta(asm_t *asb)
{
    instruction_t **instruction = NULL;

    if (allocate_instructions(asb) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    asb->nb_instructions = 0;
    for (asb->line = 0 ; asb->lines[asb->line] ; asb->line++) {
        if (is_not_instruction(asb->lines[asb->line]))
            continue;
        if (instruction_is_correct(asb, asb->lines[asb->line]) == false)
            return (EXIT_FAILURE);
        instruction = &(asb->instructions[asb->nb_instructions]);
        (*instruction) = instruction_create(asb->lines[asb->line]);
        (*instruction)->offset = asb->header.prog_size;
        asb->header.prog_size += (*instruction)->size;
        asb->nb_instructions++;
    }
    return (EXIT_SUCCESS);
}

static bool is_not_instruction(char const *line)
{
    return (
        my_str_is_empty(line)
        || my_str_beg(line, NAME_CMD_STRING)
        || my_str_beg(line, COMMENT_CMD_STRING)
    );
}

static int allocate_instructions(asm_t *asb)
{
    int len = 0;

    for (int i = 0 ; asb->lines[i] ; i++)
        if (is_not_instruction(asb->lines[i]) == false)
            len++;
    asb->instructions = malloc(sizeof(instruction_t *) * (len + 1));
    if (asb->instructions == NULL) {
        my_puterr("Couldn't allocate memory for instructions.\n");
        return (EXIT_FAILURE);
    }
    for (int i = 0 ; i <= len ; i++)
        asb->instructions[i] = NULL;
    return (EXIT_SUCCESS);
}