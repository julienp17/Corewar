/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** main
*/

#include <stdlib.h>
#include "champion_data.h"
#include "corewar.h"
#include "vm.h"

int main(int ac, char **av)
{
    vm_t *vm = NULL;
    get_opt_t *infos = NULL;
    int status = 0;

    if (ac < 2)
        return (84);
    infos = my_get_opt(av);
    vm = vm_create();
    if (vm == NULL)
        return (84);
    vm->nb_champions = 2;
    vm->nb_alive = vm->nb_champions;
    status = corewar(vm, infos->prog);
    vm_destroy(vm);
    return (status);
}