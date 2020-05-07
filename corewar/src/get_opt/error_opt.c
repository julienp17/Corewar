/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** error_opt
*/

#include <stdlib.h>
#include <stddef.h>
#include "file_informations.h"

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