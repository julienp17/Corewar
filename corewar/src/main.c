/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>

#include "file_control.h"
#include "file_informations.h"
#include "op.h"

int main(int ac, char **av)
{
    if (ac < 2)
        return (84);
    my_get_opt(av);
    return (0);
}