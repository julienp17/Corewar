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

void error_name(prog_info_t *info)
{
    if (info->prog_name > 4 || info->prog_name < 1 ) {
        printf("-n argument %d is invalid.\n", info->prog_name);
        printf("Enter a number between 1 and 4.\n");
        exit(1);
    }
}

int elem_add_n(prog_info_t **add, char **av, int i)
{
    if ((!my_strcmp("-n", av[i]))) {
        // (*add)->load_address = -1;
        i += 1;
        (*add)->prog_name = my_atoi(av[i]);
        error_name((*add));
        i += 1;
        if (my_strcmp("-a", av[i]) == 0) {
            i++;
            (*add)->load_address = my_atoi(av[i]);
            i++;
        }
        if (my_strcmp("-a", av[i]) && my_strcmp("-n", av[i]))
            (*add)->file_path = my_strdup(av[i]);
        else
            exit (INVALID_OPTION);
    }
    return (i);
}

int elem_add_a(prog_info_t **add, char **av, int i)
{
    if ((!my_strcmp("-a", av[i]))) { //-a argument -1 is invalid. Enter a valid memory offset.
        i += 1;
        // (*add)->load_address = my_atoi(av[i]);
        i += 1;
        if ((!my_strcmp("-n", av[i]))) {
            i++;
            (*add)->prog_name = my_atoi(av[i]);
            error_name((*add));
            i++;
        }
        if (my_strcmp("-a", av[i]) && my_strcmp("-n", av[i]))
            (*add)->file_path = my_strdup(av[i]);
        else
            exit (INVALID_OPTION);
    }
    return (i);
}

int elem_add_std(prog_info_t **add, char **av, int i)
{

    if (my_strcmp("-a", av[i]) && my_strcmp("-n", av[i])) {
        // (*add)->load_address = -1;
        (*add)->file_path = my_strdup(av[i]);
    }
    else
        exit (INVALID_OPTION);

    return (i);
}