/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Returns the name of a file without directory prefix or extension
*/

#include <stddef.h>
#include "my.h"

char *get_pretty_filename(char *ugly_filename)
{
    char *pretty_filename = NULL;
    unsigned int last_prefix_index = 0;
    unsigned int len = 0;

    pretty_filename = ugly_filename;
    for (unsigned int i = 0 ; ugly_filename[i] ; i++)
        if (ugly_filename[i] == '/')
            last_prefix_index = i + 1;
    pretty_filename += last_prefix_index;
    len = my_strlen(pretty_filename);
    for (unsigned int i = len - 1 ; i > 0 ; i--)
        if (pretty_filename[i] == '.')
            pretty_filename[i] = '\0';
    return (pretty_filename);
}