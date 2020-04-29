/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_str_isnum
*/

#include <stdbool.h>

bool my_str_isnum_neg(char const *str)
{
    int i = 0;

    if (str[0] == '-') {
        if (str[1] == '\0')
            return (false);
        i = i + 1;
    } else {
        return (false);
    }
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return (false);
        i = i + 1;
    }
    return (true);
}
