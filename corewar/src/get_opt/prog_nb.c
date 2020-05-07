/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** is_free_prog_nb
*/

#include <stddef.h>
#include <stdlib.h>
#include "file_informations.h"

int free_prog_nb(prog_info_t *my_prog, int nb_test);

int get_prog_nb(prog_info_t *my_prog)
{
    int nb_test = 1;
    int nb_free = 0;

    while (nb_test < 4) {
        nb_free = free_prog_nb(my_prog, nb_test);
        if (nb_free == nb_test)
            return (nb_test);
        nb_test++;
    }
    return (nb_test);
}

int free_prog_nb(prog_info_t *my_prog, int nb_test)
{
    prog_info_t *tmp;

    tmp = my_prog;
    while (tmp) {
        if (tmp->prog_name == nb_test)
            return (-1);
        tmp = tmp->next;
    }
    return (nb_test);
}

void erro_prog_nb(prog_info_t *my_prog, int nb_test)
{
    printf("nb_test %d\n", nb_test);
    if (free_prog_nb(my_prog, nb_test) == -1) {
        printf("Overlap detected.\n");
        exit(1);
    }
    return;
}