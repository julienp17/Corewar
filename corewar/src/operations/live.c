/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Execute a 'live' instruction
*/

#include "vm.h"
#include "my.h"

int live(vm_t *vm, proc_t *proc)
{
    int player_nb = 0;
    champion_t *champion_living = NULL;

    player_nb = proc->instruction->args[0].value;
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
    my_printf("The player %d (%s) is alive.\n", champion_living->nb,
                                        champion_living->header.prog_name);
    return (EXIT_SUCCESS);
}