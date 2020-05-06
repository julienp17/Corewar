/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Returns true if the conversion specifier is an int convertor, false otherwise
*/

#include <stdbool.h>
#include "my.h"

bool my_is_int_converter(char my_char)
{
    char const int_converters[] = INT_CONVERTERS;

    for (int i = 0 ; int_converters[i] ; i = i + 1) {
        if (my_char == int_converters[i])
            return (true);
    }
    return (false);
}