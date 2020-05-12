/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Operations
*/

#ifndef OPERATIONS_H_
    #define OPERATIONS_H_

    #include "vm.h"

    typedef struct operation {
        int code;
        int (*function)(vm_t *, champion_t *);
    } operation_t;

    int (*operation_get(int const code))(vm_t *, champion_t *);
    int live(vm_t *vm, champion_t *champion);
    int ld(vm_t *vm, champion_t *champion);
    int zjmp(vm_t *vm, champion_t *champion);
    int sti(vm_t *vm, champion_t *champion);
#endif