/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** my_str_contains
*/

#include <stdbool.h>

static bool my_find(char const *str, int i, char const *to_find);

bool my_str_contains(char const *str, char const *to_find)
{
    int i = 0;

    if (!str)
        return (false);
    while (str[i] != '\0') {
        if (my_find(str, i, to_find))
            return (true);
        i = i + 1;
    }
    return (false);
}

static bool my_find(char const *str, int i, char const *to_find)
{
    int j = 0;

    while (to_find[j] != '\0') {
        if (str[i] != to_find[j])
            return (false);
        i = i + 1;
        j = j + 1;
    }
    return (true);
}