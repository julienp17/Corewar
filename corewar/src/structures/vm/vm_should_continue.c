/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** vm_should_continue
*/

#include "vm.h"

bool vm_should_continue(vm_t *vm)
{
    return (
        vm->nb_alive > 1
        && (vm->cycle_to_dump == -1 || vm->cycle < vm->cycle_to_dump)
    );
}