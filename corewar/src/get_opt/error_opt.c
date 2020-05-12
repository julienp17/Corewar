/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** error_opt
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "champion_data.h"

void usage_display(void)
{
    printf("Usage: ./corewar [-dump cycle_nb] ");
    printf("[[-a load_addr] [-n prog_nb] prog.cor] ...\n");
    exit(1);
}
void error_cycle(int nb)
{
    if (nb < 0) {
        printf("-dump argument %d is invalid.", nb);
        printf(" Please enter a positive number.\n");
        exit(1);
    }
}

void error_arg(get_opt_t *opt)
{
    if (list_size(opt->prog) > 4) {
        printf("The number of champion load is above the limit.\n");
        exit(1);
    }
    if (list_size(opt->prog) < 2) {
        printf("Usage: ./corewar [-dump cycle_nb] [[-a load_addr] [-n prog_nb] prog.cor] ...\n");
        exit(1);
    }
}

void error_name(champion_data_t *info)
{
    if (info->prog_nb > 4 || info->prog_nb < 1 ) {
        printf("-n argument %d is invalid.\n", info->prog_nb);
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