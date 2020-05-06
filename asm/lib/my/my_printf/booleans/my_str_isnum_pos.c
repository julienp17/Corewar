/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_str_isnum
*/

#include <stdbool.h>

int my_strlen(char const *str);

bool my_str_isnum_pos(char const *str)
{
    unsigned int i = 0;

    if (!str[i])
        return (false);
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return (false);
        i = i + 1;
    }
    return (true);
}
