/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** fill_champion
*/

#include <stddef.h>
#include "vm.h"
#include "my.h"
#include "champion_data.h"

void fill_champion(vm_t *vm, get_opt_t *opt)
{
    champion_data_t *tmp = NULL;
    int nb_champion = list_size(opt->prog);
    int i = 0;

    tmp = opt->prog;
    vm->cycle = opt->nb_cycle;
    vm->nb_champions = nb_champion;
    vm->nb_alive = nb_champion;
    while (tmp != NULL ) {
        vm->champions[i].nb = tmp->prog_nb;
        vm->champions[i].proc->pc = tmp->load_address;
        vm->champions[i].file_path = my_strdup(tmp->file_path);
        tmp = tmp->next;
        i++;
    }
    return;
}