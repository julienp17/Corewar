/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** get_header
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "file_informations.h"
#include "op.h"
#include <stdio.h>
#include "my.h"

header_t get_header(int fd)
{
    header_t header;
    int read_size = sizeof(int) +
                    (sizeof(char) * PROG_NAME_LENGTH) +
                    (sizeof(int)) +
                    (sizeof(char) * COMMENT_LENGTH);
    char buf[read_size];

    read(fd, &buf, sizeof(int));
    header.magic = *(int *) buf;
    read(fd, &buf, (sizeof(char) * PROG_NAME_LENGTH));
    my_strcpy(header.prog_name, buf);
    read(fd, &buf, sizeof(int));
    read(fd, &buf, sizeof(int));
    header.prog_size = *(int *) buf;
    read(fd, &buf, (sizeof(char) * COMMENT_LENGTH));
    my_strcpy(header.comment, buf);
    return header;
}