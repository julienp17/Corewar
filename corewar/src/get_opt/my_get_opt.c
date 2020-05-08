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

int add_prog_infos(char **av, int i , my_get_opt_t *opt)
{
    prog_info_t *tmp = NULL;
    prog_info_t *add = NULL;
    int reference = i;
    add = malloc(sizeof(prog_info_t));
    tmp = opt->prog;


    i = elem_add_n(&add, av, i);
    i = elem_add_a(&add, av, i, opt);
    i = elem_add_std(&add, av, i, opt);

    if (tmp == NULL) {
        opt->prog = add;
        return (i);
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = add;
    return (i);
}

my_get_opt_t *my_get_opt(char **av)
{
    my_get_opt_t *opt = NULL;

    opt = malloc(sizeof(my_get_opt_t));
    opt->prog = NULL;
    for (int i = 1; av[i]; i++) {
        if ((!my_strcmp("-dump", av[i])) || (!my_strcmp("-d", av[i]))) {
            opt->nb_cycle = my_atoi(av[(i + 1)]);
            i += 2;
        }
        i = add_prog_infos(av, i, opt);
    }
    //display_prog(opt);
    // printf("HERE\n");
    return (opt);
}

void display_prog(my_get_opt_t *opt)
{
    printf("DISPLAY:\n");
    while (opt->prog) {
        printf("opt->prog->prog_name = [%d]\n", opt->prog->prog_name);
        printf("opt->prog->load_address = [%d]\n", opt->prog->load_address);
        printf("opt->prog->file_path = [%s]\n\n\n\n", opt->prog->file_path);
        opt->prog = opt->prog->next;
    }
}