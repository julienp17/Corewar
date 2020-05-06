/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** read_file
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "op.h"
#include "my.h"
#include "file_informations.h"

static int open_file(char *fp);

    void read_files(prog_info_t *filepaths, int nb_prog)
{
    int fd = 0;
    files_inf_t **files = malloc(sizeof(files_inf_t) * nb_prog + 1);
    prog_info_t *tmp = filepaths;

    files[nb_prog] = NULL;
    for (int i = 0; tmp; i++) {
        fd = open_file(tmp->file_path);
        files[i]->header = get_header(fd);
        close(fd);
        tmp = tmp->next;
    }
}

static int open_file(char *fp)
{
    int fd = 0;

    fd = open(fp, O_RDONLY);
    if (fd < 0) {
        my_puterr("Can't open file: ");
        my_puterr(fp);
        my_puterr(".\n");
        exit(EXIT_FAILURE);
    }
    return fd;
}