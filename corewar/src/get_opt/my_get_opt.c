/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** my_get_ppt
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "file_informations.h"

void display_prog(get_opt_t *opt);
int list_size(prog_info_t *prog);

int add_elements(prog_info_t *add, int i, char **av, get_opt_t *opt)
{
    if (av[i] != NULL && (!my_strcmp("-a", av[i]))) {
        i = elem_add_a(add, av, i, opt);
    }
    else if (av[i] != NULL && (!my_strcmp("-n", av[i]))) {
        i = elem_add_n(add, av, i, opt);
    }
    else {
        i = elem_add_std(add, av, i, opt);
    }
}

int add_prog_infos(char **av, int i , get_opt_t *opt)
{
    prog_info_t *tmp = NULL;
    prog_info_t *add = NULL;

    add = malloc(sizeof(prog_info_t));
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

get_opt_t *my_get_opt(char **av)
{
    get_opt_t *opt = NULL;

    opt = malloc(sizeof(get_opt_t));
    opt->prog = NULL;
    for (int i = 1; av[i]; i++) {
        if ((!my_strcmp("-dump", av[i])) || (!my_strcmp("-d", av[i]))) {
            opt->nb_cycle = my_atoi(av[(i + 1)]);
            i += 2;
        }
        i = add_prog_infos(av, i, opt);
    }
    if (list_size(opt->prog) > 4) {
        printf("The number of champion load is above the limit.\n");
        exit(1);
    }
    display_prog(opt);
    free_list(opt->prog);
    return (opt);
}

int list_size(prog_info_t *prog)
{
    prog_info_t *tmp = NULL;
    int i = 0;

    tmp = prog;
    while (tmp) {
        i++;
        tmp = tmp->next;
    }
    return (i);
}
void display_prog(get_opt_t *opt)
{
    printf("DISPLAY:\n");
    while (opt->prog) {
        printf("opt->prog->prog_name = [%d]\n", opt->prog->prog_name);
        printf("opt->prog->load_address = [%d]\n", opt->prog->load_address);
        printf("opt->prog->file_path = [%s]\n\n\n\n", opt->prog->file_path);
        opt->prog = opt->prog->next;
    }
}