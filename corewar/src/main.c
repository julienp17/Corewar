/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include "file_read.h"
#include "op.h"

int main(int ac, char **av)
{
    buffer_t buf;
    int offset = 0;
    int offsets[] = {
        sizeof(int), sizeof(char) * PROG_NAME_LENGTH,
        sizeof(int), sizeof(int), sizeof(char) * COMMENT_LENGTH, sizeof(int),
        sizeof(char), 0
    };

    if (ac != 2) {
        return (1);
    }
    if (buffer_fill_from_file(av[1], &buf) == EXIT_FAILURE)
        return (1);
    for (int i = 0 ; offsets[i] != 0 ; i++) {
        if (offsets[i] == sizeof(int))
            printf("%x\n", *(int *)(buf.buf + offset));
        else
            printf("%s\n", (char *)(buf.buf + offset));
        offset += offsets[i];
    }
    return (0);
}