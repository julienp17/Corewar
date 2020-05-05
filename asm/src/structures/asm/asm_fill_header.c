/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** Fill header information in assembler structure
*/

#include "asm.h"
#include "my.h"

static int fill_program_name(asm_t *asb);

int asm_fill_header(asm_t *asb)
{
    while (asb->lines[asb->line] && my_str_is_empty(asb->lines[asb->line]))
        asb->line++;
    if (fill_program_name(asb) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

static int fill_program_name(asm_t *asb)
{
    char **tokens = NULL;

    if (my_str_beg(asb->lines[asb->line], NAME_CMD_STRING) == false) {
        asb->line = 0;
        asm_puterr(asb, "No name specified");
        return (EXIT_FAILURE);
    }
    tokens = my_str_to_word_array(asb->lines[asb->line], '"');
    my_strarr_remove_empty(tokens);
    if (my_strarr_len(tokens) != 2) {
        asm_puterr(asb, "Syntax Error");
        return (EXIT_FAILURE);
    }
    if (my_strlen(tokens[1]) > PROG_NAME_LENGTH) {
        asm_puterr(asb, "The program name is too long");
        return (EXIT_FAILURE);
    }
    my_strcpy(asb->header.prog_name, tokens[1]);
    my_free_str_array(tokens);
    return (EXIT_SUCCESS);
}