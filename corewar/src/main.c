/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** main
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "op.h"

void pars_data(char **av)
{
    int fd = 0;
    void *buffer = NULL;

    buffer = malloc(sizeof(int));
    fd = open(av[1], O_RDONLY);

    while (read(fd, buffer, sizeof(int))) {
        printf("%x ", *(int *)buffer);
    }
}

int main(int ac, char **av)
{
    if (ac < 2)
        return (84);

    pars_data(av);
    return (0);
}