/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** get_prog
*/

#include "file_informations.h"
#include <unistd.h>

void get_prog(fd)
{
    int read_size = sizeof(int) +
                    (sizeof(char) * PROG_NAME_LENGTH) +
                    (sizeof(int)) +
                    (sizeof(char) * COMMENT_LENGTH);
    char buf[read_size];

    read(fd, &buf, read_size);
    read_size = sizeof(char);
    for (int status = 0; status > 0; status = read(fd, &buf, read_size)) {
        
    }
}