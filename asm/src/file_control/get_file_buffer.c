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
#include "my.h"
#include "file_control.h"

char *get_file_buffer(char const *filepath)
{
    int fd = 0;
    char *buffer = NULL;
    unsigned int file_size = get_file_size(filepath);

    buffer = malloc(sizeof(char) * (file_size + 1));
    if (buffer == NULL) {
        my_puterr("Couldn't allocate memory for file buffer.\n");
        return (NULL);
    }
    fd = open(filepath, O_RDONLY);
    if (fd < 0) {
        my_puterr("Couldn't open file buffer.\n");
        return (NULL);
    }
    if (read(fd, buffer, file_size) == -1) {
        my_puterr("Coudln't read file buffer.\n");
        return (NULL);
    }
    buffer[file_size] = '\0';
    close(fd);
    return (buffer);
}