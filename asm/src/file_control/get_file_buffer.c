/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Get the file buffer
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "file_control.h"
#include "my.h"

static int fill_buffer(char const *filepath, ssize_t file_size, char *buffer);

char *get_file_buffer(char const *filepath)
{
    char *buffer = NULL;
    ssize_t file_size = 0;

    file_size = get_file_size(filepath);
    if (file_size < 0)
        return (NULL);
    buffer = malloc(sizeof(char) * (file_size + 1));
    if (buffer == NULL) {
        my_eprintf("%s : couldn't allocate memory for file buffer.\n",filepath);
        return (NULL);
    }
    buffer[file_size] = '\0';
    if (fill_buffer(filepath, file_size, buffer) == EXIT_FAILURE)
        return (NULL);
    return (buffer);
}

static int fill_buffer(char const *filepath, ssize_t file_size, char *buffer)
{
    int fd = 0;
    ssize_t read_size = 0;
    int status = EXIT_SUCCESS;

    fd = open(filepath, O_RDONLY);
    if (fd < 0) {
        my_eprintf("%s : couldn't open file.\n", filepath);
        return (EXIT_FAILURE);
    }
    read_size = read(fd, buffer, file_size);
    if (read_size == -1) {
        my_eprintf("%s : couldn't read file.\n", filepath);
        status = EXIT_FAILURE;
    }
    if (close(fd) < 0) {
        my_eprintf("%s : couldn't close file.\n", filepath);
        status = EXIT_FAILURE;
    }
    return (status);
}