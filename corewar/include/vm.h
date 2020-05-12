/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Header file for the virtual machine
*/

#ifndef VIRTUAL_MACHINE_H_
    #define VIRTUAL_MACHINE_H_

    #include "op.h"
    #include "champion.h"

    #define MAX_CHAMPIONS          4

    typedef unsigned char uchar;
    typedef struct virtual_machine {
        char mem[MEM_SIZE];
        champion_t champions[MAX_CHAMPIONS];
    } vm_t;

    vm_t *vm_create(void);
    void vm_destroy(vm_t *vm);

    void vm_dump_mem(vm_t *vm);
#endif