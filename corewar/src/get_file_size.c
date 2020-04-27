/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** Return the number of bytes in a file
*/

#include <unistd.h>
#include <fcntl.h>
#include "file_read.h"

ssize_t get_file_size(char const *filename)
{
    ssize_t file_size = 0;
    ssize_t read_size = 1;
    int fd = 0;
    char buffer[READ_SIZE] = "";

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (1);
    while (read_size > 0) {
        read_size = read(fd, buffer, READ_SIZE);
        file_size += read_size;
    }
    close(fd);
    return (file_size);
}