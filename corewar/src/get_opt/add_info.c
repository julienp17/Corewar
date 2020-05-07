/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** add_info
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "file_informations.h"

void error_name(prog_info_t *info);
void err_address(int nb);

int elem_add_n(prog_info_t *add, char **av, int i, get_opt_t *opt)
{
    printf("in add n\n");
    add->load_address = -1;
    i += 1;
    erro_prog_nb(opt->prog, my_atoi(av[i]));
    add->prog_name = my_atoi(av[i]);
    error_name(add);
    i += 1;
    if (my_strcmp("-a", av[i]) == 0) {
        i++;
        add->load_address = my_atoi(av[i]);
        i++;
    }
    if (my_strcmp("-a", av[i]) && my_strcmp("-n", av[i])) {
        add->file_path = my_strdup(av[i]);
    }
    else
        exit (INVALID_OPTION);
    return (i);
}

int elem_add_a(prog_info_t *add, char **av, int i, get_opt_t *tmp)
{
    printf("in add a\n");
    i += 1;
    add->load_address = my_atoi(av[i]);
    err_address(add->load_address);
    i += 1;
    if ((!my_strcmp("-n", av[i]))) {
        i++;
        add->prog_name = my_atoi(av[i]);
        error_name(add);
        i++;
    }
    else {
        add->prog_name = get_prog_nb(tmp->prog);
    }
    if (my_strcmp("-a", av[i]) && my_strcmp("-n", av[i])) {
        add->file_path = my_strdup(av[i]);
    }
    else
        exit (INVALID_OPTION);
    return (i);
}

int elem_add_std(prog_info_t *add, char **av, int i, get_opt_t *opt)
{

    printf("in add std\tav [%s]\n", av[i]);
    add->file_path = my_strdup(av[i]);
    add->prog_name  = get_prog_nb(opt->prog);;
    add->load_address = -1;
    return (i);
}

void error_name(prog_info_t *info)
{
    if (info->prog_name > 4 || info->prog_name < 1 ) {
        printf("-n argument %d is invalid.\n", info->prog_name);
        printf("Enter a number between 1 and 4.\n");
        exit(1);
    }
}

void err_address(int nb)
{
    if (nb < 0) {
        printf("-a argument %d is invalid.\n", nb);
        printf("Enter a valid memory offset.\n");
        exit(1);
    }

}