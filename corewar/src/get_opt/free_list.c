/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** free_list
*/

#include <stddef.h>
#include "file_informations.h"

prog_info_t *free_list(prog_info_t *list)
{
    prog_info_t *tmp = NULL;

    if (list == NULL)
        return (NULL);
    tmp = list->next;
    free(list);
    return (free_list(tmp));
}