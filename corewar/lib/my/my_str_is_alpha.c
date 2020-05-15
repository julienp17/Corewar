/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Returns true if string is composed of letters
*/

#include <stdbool.h>

bool my_char_is_alpha(char const my_char);

bool my_str_is_alpha(char const *str)
{
    for (unsigned int i = 0 ; str[i] ; i++)
        if (!my_char_is_alpha(str[i]))
            return (false);
    return (true);
}