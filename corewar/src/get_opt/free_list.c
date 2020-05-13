/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** free_list
*/

#include <stdlib.h>
#include "champion_data.h"

champion_data_t *free_list(champion_data_t *list)
{
    champion_data_t *tmp = NULL;

    if (list == NULL)
        return (NULL);
    tmp = list->next;
    free(list);
    return (free_list(tmp));
}