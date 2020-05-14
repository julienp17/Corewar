/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Checks if a string is numerical
*/

#include <stdbool.h>

bool my_str_isnum(char const *str)
{
    int i = 0;

    if (str[0] == '-' && str[1] != '\0')
        i = i + 1;
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return (false);
        i = i + 1;
    }
    return (true);
}