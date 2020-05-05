/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** Fill the assembler structure while looking for errors
*/

#include "asm.h"
#include "my.h"

static bool header_is_empty(asm_t *asb);

int asm_fill(asm_t *asb)
{
    char *line = NULL;
    int status = EXIT_SUCCESS;

    if (asm_fill_instructions_meta(asb) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    asb->nb_instructions = 0;
    for (; status == EXIT_SUCCESS && asb->lines[asb->line] ; asb->line++) {
        line = asb->lines[asb->line];
        if (my_str_is_empty(line))
            continue;
        if (my_str_beg(line, NAME_CMD_STRING))
            status = asm_fill_program_name(asb, line);
        else if (my_str_beg(line, COMMENT_CMD_STRING))
            status = asm_fill_comment(asb, line);
        else
            status = asm_fill_instruction_value(asb, line);
    }
    if (status == EXIT_SUCCESS && header_is_empty(asb))
        return (EXIT_FAILURE);
    asb->header.prog_size = swap_int32(asb->header.prog_size);
    return (status);
}

static bool header_is_empty(asm_t *asb)
{
    bool is_empty = false;

    if (my_str_is_empty(asb->header.comment)) {
        asb->line = 0;
        asm_puterr(asb, "Warning : No comment specified");
    }
    if (my_str_is_empty(asb->header.prog_name)) {
        asb->line = 0;
        asm_puterr(asb, "No name specified");
        is_empty = true;
    }
    return (is_empty);
}