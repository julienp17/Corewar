/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Returns true if the conversion specifier is an int convertor, false otherwise
*/

#include <stdbool.h>
#include "my.h"

bool my_is_int_unsigned_converter(char my_char)
{
    char const unsigned_int_converters[] = UNSIGNED_INT_CONVERTERS;

    for (int i = 0 ; unsigned_int_converters[i] ; i = i + 1) {
        if (my_char == unsigned_int_converters[i])
            return (true);
    }
    return (false);
}