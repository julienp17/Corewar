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

void display_prog(my_get_opt_t *opt);

int elem_add(prog_info_t **add, char **av, int i)
{
    int pos = i;

    (*add)->load_address = -1;
    if ((!my_strcmp("-n", av[pos]))) {
        pos += 1;
        (*add)->prog_name = my_atoi(av[pos]);
        pos += 1;
        if (av[pos] != NULL && (!my_strcmp("-a", av[pos]))) {
            pos++;
            (*add)->load_address = my_atoi(av[pos]);
            pos++;
        }
        if (av[pos] != NULL)
            (*add)->file_path = my_strdup(av[pos]);
        else {
            return (INVALID_OPTION);
        }
    }
    return (0);
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
            add_prog_infos(av, i, opt);
        }
    }
    display_prog(opt);
    return (opt);
}

void display_prog(my_get_opt_t *opt)
{
    while (opt->prog) {
        printf("opt->prog->prog_name = [%d]\n", opt->prog->prog_name);
        printf("opt->prog->load_address = [%d]\n", opt->prog->load_address);
        printf("opt->prog->file_path = [%s]\n\n\n\n", opt->prog->file_path);
        opt->prog = opt->prog->next;
    }

}