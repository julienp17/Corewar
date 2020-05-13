/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Header file for the virtual machine
*/

#ifndef VIRTUAL_MACHINE_H_
    #define VIRTUAL_MACHINE_H_

    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include "op.h"
    #include "champion.h"

    #define MAX_CHAMPIONS          4

    typedef unsigned char uchar;
    typedef struct virtual_machine {
        char mem[MEM_SIZE];
        champion_t champions[MAX_CHAMPIONS];
        uchar nb_champions;
        uchar nb_alive;
        int cycle;
        int cycle_to_die;
        int nb_live;
    } vm_t;

    vm_t *vm_create(void);
    void vm_destroy(vm_t *vm);
    void fill_champion(vm_t *vm, get_opt_t *opt);

    int vm_load_champion(vm_t *vm, champion_t *champion);
    void vm_dump(vm_t *vm);
#endif