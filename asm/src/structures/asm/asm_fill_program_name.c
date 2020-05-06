/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** Fill the program name
*/

#include "asm.h"
#include "my.h"

static bool asm_state_is_good(asm_t *asb);
static bool tokens_are_correct(asm_t *asb, char **tokens);

int asm_fill_program_name(asm_t *asb, char const *line)
{
    char **tokens = NULL;

    if (asm_state_is_good(asb) == false)
        return (EXIT_FAILURE);
    tokens = my_str_to_word_array(line, '"');
    my_strarr_remove_empty(tokens);
    if (tokens_are_correct(asb, tokens) == false)
        return (EXIT_FAILURE);
    my_strcpy(asb->header.prog_name, tokens[1]);
    my_free_str_array(tokens);
    return (EXIT_SUCCESS);
}

static bool asm_state_is_good(asm_t *asb)
{
    if (asm_has_an_instruction(asb)) {
        asm_puterr(asb, "The name of your program must be the first line");
        return (false);
    }
    if (my_str_is_empty(asb->header.comment) == false) {
        asm_puterr(asb, "The comment can only be defined once");
        return (false);
    }
    return (true);
}

static bool tokens_are_correct(asm_t *asb, char **tokens)
{
    if (my_strarr_len(tokens) == 1) {
        asm_puterr(asb, "No name specified");
        return (false);
    }
    if (my_strarr_len(tokens) > 2) {
        asm_puterr(asb, "Syntax Error");
        return (false);
    }
    if (my_strlen(tokens[1]) > PROG_NAME_LENGTH) {
        asm_puterr(asb, "The program name is too long");
        return (false);
    }
    return (true);
}