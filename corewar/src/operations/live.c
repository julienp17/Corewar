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
    for (int i = 0 ; champion_living == NULL && i < MAX_CHAMPIONS ; i++)
        if (player_nb == vm->champions[i].nb)
            champion_living = &(vm->champions[i]);
    if (champion_living) {
        champion_living->last_live = vm->cycle;
        printf("The player %d(%s) is alive.\n", champion_living->nb,
                                                champion->header.prog_name);
    }
    return (EXIT_SUCCESS);
}