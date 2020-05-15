/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Get precision in format
*/

#include "my.h"

int my_get_precision(char **format)
{
    char *str = my_strdup(*format);
    unsigned int i = 0;

    while (str[i] && str[i] != '.')
        i++;
    if (str[i] == '.') {
        (*format)[i] = '\0';
        i++;
        if (!my_str_isnum_pos(str + i))
            return (-1);
        return (my_strnum_to_uint(str + i));
    }
    return (0);
}