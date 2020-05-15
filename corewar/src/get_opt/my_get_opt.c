    /*
** EPITECH PROJECT, 2020
** corewar
** File description:
** my_get_ppt
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "champion_data.h"

void display_opt(get_opt_t *opt);

int add_elements(champion_data_t *add, int i, char **av, get_opt_t *opt)
{
    if (av[i] != NULL && ((!my_strcmp("-dump", av[i]))
        || (!my_strcmp("-d", av[i])))) {
        opt->nb_cycle = my_atoi(av[(i + 1)]);
        error_cycle(opt->nb_cycle);
        i += 2;
    }
    if (av[i] != NULL && (!my_strcmp("-a", av[i]))) {
        i = elem_add_a(add, av, i, opt);
    }
    else if (av[i] != NULL && (!my_strcmp("-n", av[i]))) {
        i = elem_add_n(add, av, i, opt);
    }
    else if (av[i] != NULL) {
        i = elem_add_std(add, av, i, opt);
    }
    return (i);
}

int add_prog_infos(char **av, int i , get_opt_t *opt)
{
    champion_data_t *tmp = NULL;
    champion_data_t *add = NULL;

    add = malloc(sizeof(champion_data_t));
    tmp = opt->prog;

    i = add_elements(add, i, av, opt);
    if (tmp == NULL) {
        add->next = NULL;
        opt->prog = add;
        return (i);
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    add->next = NULL;
    tmp->next = add;
    return (i);
}