/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** Returns a copy of a string in lowercase
*/

#include <stdbool.h>

bool my_char_is_alpha_upper(char const my_char);

char *my_str_to_lower(char *str)
{
    for (unsigned int i = 0 ; str[i] ; i++) {
        if (my_char_is_alpha_upper(str[i]))
            str[i] = str[i] + 'a' - 'A';
    }
    return (str);
}