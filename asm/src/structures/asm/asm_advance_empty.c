/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** Loop through the file lines until the next line is non-empty
*/

#include "asm.h"
#include "my.h"

void asm_advance_empty(asm_t *asb)
{
    while (asb->lines[asb->line] && my_str_is_empty(asb->lines[asb->line]))
        asb->line++;
}