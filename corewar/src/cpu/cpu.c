/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** exec_instruction
*/

#include <stdio.h>
#include "op.h"
#include "champion_data.h"

int exec_instruc(files_inf_t *files, int cycle)
{
    char *ram = NULL;
    int i = 0;

    ram = malloc(sizeof(char) * MEM_SIZE);
    load_champion(files, &ram);
    for (size_t i = 1; i <= cycle; i++) {

    }
    free(ram);
    return (0);
}