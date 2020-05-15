/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Header file for champion structure
*/

#ifndef CHAMPION_H_
    #define CHAMPION_H_

    #include <stdbool.h>
    #include "op.h"
    #include "proc.h"

    #define CHAMPION_IS_ALIVE(vm, champion) \
        (vm->cycle - champion->last_live < vm->cycle_to_die)

    typedef struct champion {
        header_t header;
        char *file_path;
        int nb;
        int last_live;
        int nb_proc;
        struct process *proc;
    } champion_t;

    int champion_load_header(champion_t *champion, int fd);
#endif