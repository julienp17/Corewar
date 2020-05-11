/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** corewar
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "champion_data.h"
#include "virtual_machine.h"
#include "my.h"
#include "corewar.h"

int corewar(champion_data_t *filepaths, int nb_prog)
{
    vm_t *vm = NULL;
    int fd = 0;

    vm = vm_create();
    if (vm == NULL)
        return (EXIT_FAILURE);
    for (int i = 0 ; i < nb_prog ; i++) {
        fd = open(filepaths->file_path, O_RDONLY);
        if (fd < 0) {
            my_puterr("Couldn't open file.\n");
            return (EXIT_FAILURE);
        }
        if (champion_load_header(&(vm->champions[i]), fd) == EXIT_FAILURE)
            return (EXIT_FAILURE);
        vm->champions[i].nb = filepaths->prog_nb;
        vm->champions[i].is_alive = true;
        if (close(fd) < 0) {
            my_puterr("Couldn't open file.\n");
            return (EXIT_FAILURE);
        }
        filepaths = filepaths->next;
    }
    vm_destroy(vm);
    return (EXIT_SUCCESS);
}