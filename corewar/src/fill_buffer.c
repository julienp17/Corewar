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
#include "file_control.h"
#include "my.h"

static int allocate_buffer(char const *filename, buffer_t *buf);

int buffer_fill_from_file(char const *filename, buffer_t *buf)
{
    int fd = 0;
    int status = 0;

    if (allocate_buffer(filename, buf) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        my_puterr("Can't open the file.\n");
        return (EXIT_FAILURE);
    }
    status = read(fd, buf->buf, buf->size);
    if (status == -1) {
        my_puterr("Error reading file.\n");
    }
    if (close(fd) < 0) {
        my_puterr("Can't close the file.\n");
        return (EXIT_FAILURE);
    }
    return (status);
}

static int allocate_buffer(char const *filename, buffer_t *buf)
{
    buf->size = get_file_size(filename);
    if (buf->size < 0) {
        my_puterr("Wrong file size.\n");
        return (EXIT_FAILURE);
    }
    buf->buf = malloc(buf->size);
    if (buf->buf == NULL) {
        my_puterr("Allocating buffer's memory has not succeed");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}