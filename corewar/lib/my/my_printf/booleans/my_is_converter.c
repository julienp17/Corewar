/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Returns true if the given char is a conversion specifier, false otherwise
*/

#include <stdbool.h>
#include "my.h"

bool my_is_converter(char const my_char)
{
    char const converters[] = CONVERTERS_SPECIFIERS;

    for (int i = 0 ; converters[i] ; i = i + 1) {
        if (my_char == converters[i])
            return (true);
    }
    return (false);
}