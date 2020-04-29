/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Returns true if string is composed of undercase letters
*/

#include <stdbool.h>

bool my_char_is_alpha_lower(char const my_char);

bool my_str_is_alphalower(char const *str)
{
    for (unsigned int i = 0 ; str[i] ; i++)
        if (!my_char_is_alpha_lower(str[i]))
            return (false);
    return (true);
}