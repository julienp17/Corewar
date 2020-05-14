/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Get the width field
*/

#include <stdbool.h>

#include "my.h"

bool my_char_is_digit(char const my_char);
char *my_strdup(char const *str);

unsigned int my_get_width_field(char **format)
{
    char *str = my_strdup(*format);
    unsigned int i = 0;

    while (str[i] && !my_char_is_digit(str[i]))
        i++;
    if (my_char_is_digit(str[i]) && str[i] == '0') {
        i++;
        while (str[i] && !my_char_is_digit(str[i]))
            i++;
    }
    if (my_char_is_digit(str[i])) {
        (*format)[i] = '\0';
        return (my_strnum_to_uint(str + i));
    }
    return (0);
}