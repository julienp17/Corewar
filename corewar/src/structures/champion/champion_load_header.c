/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Load the header of a champion
*/

#include <stdlib.h>
#include <unistd.h>
#include "champion.h"
#include "my.h"
#include "corewar.h"

static int fill_header(champion_t *champion, int fd);

int champion_load_header(champion_t *champion, int fd)
{
    if (fill_header(champion, fd) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (champion->header.magic != COREWAR_EXEC_MAGIC) {
        my_puterr("Wrong executable magic number.\n");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

static int fill_header(champion_t *champion, int fd)
{
    char buf[PROG_NAME_LENGTH] = "";

    read(fd, &buf, sizeof(int));
    champion->header.magic = swap_int32(*(int *) buf);
    read(fd, champion->header.prog_name, (sizeof(char) * PROG_NAME_LENGTH));
    read(fd, &buf, sizeof(int));
    read(fd, &buf, sizeof(int));
    champion->header.prog_size = swap_int32(*(int *) buf);
    read(fd, champion->header.comment, (sizeof(char) * COMMENT_LENGTH));
    read(fd, &buf, (sizeof(int)));
    return (EXIT_SUCCESS);
}