/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** decode
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "file_read.h"

static int allocate_buffer(char const *filename, buffer_t *buf);

int buffer_fill_from_file(char const *filename, buffer_t *buf)
{
    int fd = 0;
    int status = 0;

    if (allocate_buffer(filename, buf) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        // my_puterr("");
        return (EXIT_FAILURE);
    }
    status = read(fd, buf->buf, buf->size);
    if (status == -1)
        fprintf(stderr, "ne m'oublie pas tristan stp, efface cette ligne et remplace par my_puterr\n");
    if (close(fd) < 0) {
        // my_puterr("")
        return (EXIT_FAILURE);
    }
    return (status);
}

static int allocate_buffer(char const *filename, buffer_t *buf)
{
    buf->size = get_file_size(filename);
    if (buf->size < 0) {
        // my_puterr();
        return (EXIT_FAILURE);
    }
    buf->buf = malloc(buf->size);
    if (buf->buf == NULL) {
        // my_puterr();
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}