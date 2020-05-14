/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Returns true if s1 ends with s2, false otherwise
*/

#include <stddef.h>
#include <stdbool.h>
#include "my.h"

bool my_str_ends(char const *str, char const *end)
{
    unsigned int str_len = 0;
    unsigned int end_len = 0;

    if (str == NULL || end == NULL)
        return (false);
    str_len = my_strlen(str);
    end_len = my_strlen(end);
    if (end_len > str_len)
        return (false);
    for (unsigned int i = str_len - end_len, j = 0 ; str[i] ; i++, j++)
        if (str[i] != end[j])
            return (false);
    return (true);
}