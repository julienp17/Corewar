/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Main file for assembler
*/

#include <stdlib.h>
#include "my.h"
#include "asm.h"

int main(int ac, char **av)
{
    int status = 0;

    if (ac != 2) {
        my_puterr("asm: Incorrect number of arguments.\n");
        my_putstr(ASM_HELP);
        return (EXIT_FAILURE);
    }
    if (my_strcmp(av[1], "-h") == 0) {
        my_putstr(ASM_HELP);
        return (EXIT_SUCCESS);
    }
    status = assemble(av[1]);
    return (status);
}