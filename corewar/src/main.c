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

int main(int ac, char **av)
{
    if (ac < 2) {
        usage_display();
        return (1);
    }
    my_get_opt(av);
    return (0);
}