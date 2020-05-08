/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>

#include "file_control.h"
#include "champion_data.h"
#include "op.h"
#include "instructions.h"

int main(int ac, char **av)
{
    get_opt_t *infos = NULL;

    if (ac < 2)
        return (84);
    infos = my_get_opt(av);
    read_files(infos->prog, 1);
    return (0);
}