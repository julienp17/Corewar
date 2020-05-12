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
    #include "instruction.h"

    typedef struct champion {
        header_t header;
        bool is_alive;
        int nb;
        int cycle_wait;
        int last_live;
        int regs[REG_NUMBER];
        int pc;
        instruction_t *instruction;
        bool carry;
    } champion_t;

    int champion_load_header(champion_t *champion, int fd);
#endif