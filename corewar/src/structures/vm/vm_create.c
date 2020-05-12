/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Returns a newly allocated vm structure
*/

#include <stdlib.h>
#include "vm.h"
#include "my.h"

static void init_mem(char mem[MEM_SIZE]);
static void init_champions(champion_t champions[MAX_CHAMPIONS]);

vm_t *vm_create(void)
{
    vm_t *vm = NULL;

    vm = malloc(sizeof(vm_t));
    if (vm == NULL) {
        my_puterr("Couldn't allocate memory for vm structure.\n");
        return (NULL);
    }
    init_mem(vm->mem);
    vm->nb_champions = 0;
    vm->nb_alive = 0;
    init_champions(vm->champions);
    return (vm);
}

static void init_mem(char mem[MEM_SIZE])
{
    for (int i = 0 ; i < MEM_SIZE ; i++)
        mem[i] = 0;
}

static void init_champions(champion_t champions[MAX_CHAMPIONS])
{
    for (int i = 0 ; i < MAX_CHAMPIONS ; i++) {
        champions[i].header = (header_t) {0, {0}, 0, {0}};
        champions[i].carry = false;
        champions[i].cycle_wait = 0;
        champions[i].is_alive = false;
        champions[i].instruction = instruction_create();
        champions[i].pc = 0;
        champions[i].last_live = 0;
        champions[i].nb = 0;
        for (int j = 0 ; j < REG_NUMBER ; j++)
            champions[i].registers[i] = 0;
    }
}