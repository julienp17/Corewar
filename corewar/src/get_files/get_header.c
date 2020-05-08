/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** get_header
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "champion_data.h"
#include "op.h"
#include "my.h"
#include "corewar.h"
#include "instructions.h"

header_t get_header(int fd)
{
    header_t header;
    int read_size = sizeof(int) +
                    (sizeof(char) * PROG_NAME_LENGTH) +
                    (sizeof(int)) +
                    (sizeof(char) * COMMENT_LENGTH);
    char buf[read_size];

    read(fd, &buf, sizeof(int));
    header.magic = swap_int32(*(int *) buf);
    read(fd, &buf, (sizeof(char) * PROG_NAME_LENGTH));
    my_strcpy(header.prog_nb, buf);
    read(fd, &buf, sizeof(int));
    read(fd, &buf, sizeof(int));
    header.prog_size = swap_int32(*(int *) buf);
    read(fd, &buf, (sizeof(char) * COMMENT_LENGTH));
    read(fd, &buf, (sizeof(int)));
    my_strcpy(header.comment, buf);
    return header;
}