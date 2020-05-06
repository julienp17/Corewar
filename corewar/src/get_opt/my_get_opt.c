/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** my_get_ppt
*/

#include <stdio.h>
#include <stdlib.h>
#include "file_informations.h"
#include "my.h"

void elem_add(prog_info_t **add, char **av, int i)
{
    (*add)->prog_name = my_strdup(av[i]);

    if (av[i + 1] != NULL && my_strcmp(av[i + 1], "-a") == 0) {
        if (av[i + 2] != NULL)
            (*add)->load_address = my_atoi(av[i + 2]);
    }
    else
        (*add)->load_address = -1;

}

void add_prog_infos(char **av, int i , my_get_opt_t *opt)
{
    prog_info_t *tmp = NULL;
    prog_info_t *add = NULL;

    add = malloc(sizeof(prog_info_t));
    tmp = opt->prog;
    elem_add(&add, av, i);
    if (tmp == NULL) {
        opt->prog = add;
        return;
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = add;
    return;
}

my_get_opt_t *my_get_opt(char **av)
{
    my_get_opt_t *opt = NULL;

    opt = malloc(sizeof(my_get_opt_t));
    opt->prog = NULL;
    for (size_t i = 1; av[i]; i++) {
        if ((!my_strcmp("-dump", av[i])) || (!my_strcmp("-d", av[i]))) {
            opt->nb_cycle = my_atoi(av[(i + 1)]);
            i++;
        }
        if ((!my_strcmp("-n", av[i]))) {
            i++;
            add_prog_infos(av, i, opt);
        }
    }
    return (opt);
}