/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Execute a 'live' instruction
*/

#include <stdio.h>
#include "vm.h"

int live(vm_t *vm, champion_t *champion)
{
    int player_nb = 0;
    champion_t *champion_living = NULL;

    player_nb = champion->instruction->args[0].value;
    for (int i = 0 ; champion_living == NULL && i < vm->nb_champions ; i++)
        if (player_nb == vm->champions[i].nb)
            champion_living = &(vm->champions[i]);
    if (champion_living == NULL)
        return (EXIT_FAILURE);
    vm->nb_live++;
    if (vm->nb_live >= NBR_LIVE) {
        vm->cycle_to_die -= CYCLE_DELTA;
        vm->nb_live = 0;
    }
    champion_living->last_live = vm->cycle;
    printf("The player %d (%s) is alive.\n", champion_living->nb,
                                        champion_living->header.prog_name);
    return (EXIT_SUCCESS);
}