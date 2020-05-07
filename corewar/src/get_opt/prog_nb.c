/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** is_free_prog_nb
*/

#include <stddef.h>
#include "file_informations.h"

int free_prog_nb(get_opt_t *my_prog, int nb_test);

int get_prog_nb(get_opt_t *my_prog)
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

int free_prog_nb(get_opt_t *my_prog, int nb_test)
{
    get_opt_t *tmp = NULL;

    tmp = my_prog;
    while (tmp->prog) {
        if (tmp->prog->prog_name == nb_test)
            return (-1);
        tmp->prog = tmp->prog->next;
    }
    return (nb_test);
}

// void erro_prog_nb(get_opt_t *my_prog)
// {
//     // get_opt_t *tmp = NULL;

//     // while (tmp->prog) {
//     //     if (/* condition */) {

//     //     }

//     //     tmp->prog = tmp->prog->next;
//     // }
//     return;
// }