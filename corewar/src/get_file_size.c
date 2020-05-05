/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Return the number of bytes in a file
*/

#include <unistd.h>
#include <fcntl.h>
#include "file_control.h"
#include "my.h"

ssize_t get_file_size(char const *filename)
{
    char buffer[READ_SIZE] = "";
    int fd = 0;
    ssize_t file_size = 0;
    ssize_t read_size = 1;

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        my_puterr("Can't open file.\n");
        return (-1);
    }
    while (read_size > 0) {
        read_size = read(fd, buffer, READ_SIZE);
        file_size += read_size;
    }
    if (close(fd) < 0) {
        my_puterr("Can't open file.\n");
        return (-1);
    }
    return (file_size);
}