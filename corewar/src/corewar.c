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

static void run_corewar(vm_t *vm);
static void update_alive(vm_t *vm);
static void announce_winner(vm_t *vm);

int corewar(vm_t *vm)
{
    int status = 0;
    champion_t *champion = NULL;

    for (int i = 0 ; i < vm->nb_champions ; i++) {
        champion = &(vm->champions[i]);
        status = vm_load_champion(vm, champion);
        if (status == EXIT_FAILURE)
            return (EXIT_FAILURE);
    }
    run_corewar(vm);
    return (EXIT_SUCCESS);
}

static void run_corewar(vm_t *vm)
{
    while (vm->nb_alive > 1) {
        for (int i = 0 ; i < vm->nb_champions ; i++)
            champion_execute(vm, &(vm->champions[i]));
        vm->cycle++;
        update_alive(vm);
    }
    announce_winner(vm);
}

static void update_alive(vm_t *vm)
{
    champion_t *champion = NULL;

    vm->nb_alive = 0;
    for (int i = 0 ; i < vm->nb_champions ; i++) {
        champion = &(vm->champions[i]);
        if (CHAMPION_IS_ALIVE(vm, champion))
            vm->nb_alive++;
    }
}

static void announce_winner(vm_t *vm)
{
    champion_t *winner = NULL;

    for (int i = 0 ; winner == NULL && i < vm->nb_champions ; i++) {
        winner = &(vm->champions[i]);
        if (CHAMPION_IS_ALIVE(vm, winner) == false)
            winner = NULL;
    }
    if (winner == NULL)
        winner = &(vm->champions[0]);
    my_printf("The player %d (%s) has won.\n", winner->nb,
                                            winner->header.prog_name);
}