/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Returns true if the given chars are a length modifier flag, false otherwise
*/

#include <stdbool.h>
#include <stddef.h>
#include "length_modifiers.h"

bool my_is_length_modifier(char *str)
{
    length_modifier_t length_modifiers[] = {
        {"hh", NULL},
        {"h", NULL},
        {"l", NULL},
        {"ll", NULL}
    };

    for (int i = 0 ; i < LENGTH_MODIFIERS_NB ; i = i + 1)
        if (my_strcmp(str, length_modifiers[i].symbols) == 0)
            return (true);
    return (false);
}