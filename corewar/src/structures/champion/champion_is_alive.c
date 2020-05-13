/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Returns true if the champion is alive, false otherwise
*/

#include "champion.h"

bool champion_is_alive(champion_t *champion, int cycle)
{
    return (cycle - champion->last_live < CYCLE_TO_DIE);
}