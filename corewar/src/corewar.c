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
    int status = 0;

    for (int i = 0 ; status == EXIT_SUCCESS && i < vm->nb_champions ; i++) {
        status = vm_load_champion(vm, filepaths->file_path, filepaths->prog_nb);
        if (status == EXIT_FAILURE)
            return (EXIT_FAILURE);
        filepaths = filepaths->next;
    }
    run_corewar(vm);
    return (EXIT_SUCCESS);
}

static int run_corewar(vm_t *vm)
{
    while (vm->cycle < 65) {
        champion_execute(vm, &(vm->champions[0]));
        vm->cycle++;
    }
    vm_dump(vm);
    vm->nb_alive = get_nb_alive_champions(vm);
    return (EXIT_FAILURE);
}

static char get_nb_alive_champions(vm_t *vm)
{
    char nb_alive = 0;

    for (int i = 0 ; i < MAX_CHAMPIONS ; i++) {
        if (vm->champions[i].nb < 1)
            continue;
        if (champion_is_alive(&(vm->champions[i]), vm->cycle))
            nb_alive++;
    }
    return (nb_alive);
}