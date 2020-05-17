/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** add_info
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "champion_data.h"

void error_name(champion_data_t *info);
void err_address(int nb);

int elem_add_n(champion_data_t *add, char **av, int i, get_opt_t *opt)
{
    add->load_address = -1;
    i += 1;
    erro_prog_nb(opt->prog, my_atoi(av[i]));
    add->prog_nb = my_atoi(av[i]);
    error_name(add);
    i += 1;
    if (av[i] != NULL && my_strcmp("-a", av[i]) == 0) {
        i++;
        add->load_address = my_atoi(av[i]);
        i++;
    }
    if (av[i] != NULL && my_strcmp("-a", av[i])
        && my_strcmp("-n", av[i]) && my_strcmp("-dump", av[i])) {
        add->file_path = my_strdup(av[i]);
    }
    else
        usage_display();
    return (i);
}

int elem_add_a(champion_data_t *add, char **av, int i, get_opt_t *tmp)
{
    i += 1;
    add->load_address = my_atoi(av[i]);
    err_address(add->load_address);
    i += 1;
    if (av[i] != NULL && (!my_strcmp("-n", av[i]))) {
        i++;
        erro_prog_nb(tmp->prog, my_atoi(av[i]));
        add->prog_nb = my_atoi(av[i]);
        error_name(add);
        i++;
    } else {
        add->prog_nb = get_prog_nb(tmp->prog);
    }
    if (av[i] != NULL && my_strcmp("-a", av[i])
        && my_strcmp("-n", av[i]) && my_strcmp("-dump", av[i])) {
        add->file_path = my_strdup(av[i]);
    } else
        usage_display();
    return (i);
}

int elem_add_std(champion_data_t *add, char **av, int i, get_opt_t *opt)
{
    if (av[i] != NULL && my_strcmp("-dump", av[i])) {
        add->file_path = my_strdup(av[i]);
        add->prog_nb  = get_prog_nb(opt->prog);;
        add->load_address = -1;
    }
    return (i);
}

int list_size(champion_data_t *prog)
{
    champion_data_t *tmp = NULL;
    int i = 0;

    tmp = prog;
    while (tmp) {
        i++;
        tmp = tmp->next;
    }
    return (i);
}