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
#include "vm.h"
#include "my.h"
#include "corewar.h"

static char get_nb_alive_champions(vm_t *vm);
static int run_corewar(vm_t *vm);

int corewar(vm_t *vm, champion_data_t *filepaths)
{   
    for (int i = 0 ; i < vm->nb_champions ; i++) {
        vm_load_champion(vm, filepaths->file_path, filepaths->prog_nb);
        filepaths = filepaths->next;
    }
    vm_dump_mem(vm);
    run_corewar(vm);
    return (EXIT_SUCCESS);
}

static int run_corewar(vm_t *vm)
{
    char nb_alive = 0;

    nb_alive = get_nb_alive_champions(vm);
    (void)nb_alive;
    return (EXIT_FAILURE);
}

static char get_nb_alive_champions(vm_t *vm)
{
    char nb_alive = 0;

    for (int i = 0 ; i < MAX_CHAMPIONS ; i++)
        if (vm->champions[i].is_alive)
            nb_alive++;
    return (nb_alive);
}