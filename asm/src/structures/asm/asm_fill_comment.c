/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** Fill the program comment
*/

#include "asm.h"
#include "my.h"

static bool asm_state_is_good(asm_t *asb);

int asm_fill_comment(asm_t *asb, char const *line)
{
    char **tokens = NULL;

    if (asm_state_is_good(asb) == false)
        return (EXIT_FAILURE);
    tokens = my_str_to_word_array(line, '"');
    my_strarr_remove_empty(tokens);
    if (my_strarr_len(tokens) != 2) {
        asm_puterr(asb, "Syntax Error");
        return (EXIT_FAILURE);
    }
    if (my_strlen(tokens[1]) > COMMENT_LENGTH) {
        asm_puterr(asb, "The comment is too long");
        return (EXIT_FAILURE);
    }
    my_strcpy(asb->header.comment, tokens[1]);
    my_free_str_array(tokens);
    return (EXIT_SUCCESS);
}

static bool asm_state_is_good(asm_t *asb)
{
    if (my_str_is_empty(asb->header.prog_name) || asm_has_an_instruction(asb)) {
        asm_puterr(asb, "The comment must be just after the name");
        return (false);
    }
    if (my_str_is_empty(asb->header.comment) == false) {
        asm_puterr(asb, "The comment can only be defined once");
        return (false);
    }
    return (true);
}