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

void display_prog(get_opt_t *opt);

int add_elements(champion_data_t *add, int i, char **av, get_opt_t *opt)
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

get_opt_t *my_get_opt(char **av)
{
    get_opt_t *opt = NULL;

    opt = malloc(sizeof(get_opt_t));
    opt->prog = NULL;
    opt->nb_cycle = 0;
    opt->nb_cycle = -1;
    for (int i = 1; av[i]; i++) {
        if ((!my_strcmp("-dump", av[i])) || (!my_strcmp("-d", av[i]))) {
            opt->nb_cycle = my_atoi(av[(i + 1)]);
            error_cycle(opt->nb_cycle);
            i += 2;
        }
        i = add_prog_infos(av, i, opt);
    }
    error_arg(opt);
    // display_prog(opt);
    // free_list(opt->prog);
    return (opt);
}

void display_prog(get_opt_t *opt)
{
    printf("DISPLAY:\n");
    while (opt->prog) {
        printf("opt->prog->prog_nb = [%d]\n", opt->prog->prog_nb);
        printf("opt->prog->load_address = [%d]\n", opt->prog->load_address);
        printf("opt->prog->file_path = [%s]\n\n\n\n", opt->prog->file_path);
        opt->prog = opt->prog->next;
    }
}