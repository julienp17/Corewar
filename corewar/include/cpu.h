/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cpu
*/

#ifndef CPU_H_
#define CPU_H_

#include "instruction.h"

typedef struct s_champion
{
    int prog_nb;
    int load_address;
    instr_t *instructions;
}champion_t;

void cpu(champion_t *files, int cycle);

#endif /* !CPU_H_ */
