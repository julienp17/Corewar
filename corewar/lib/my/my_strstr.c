/*
** EPITECH PROJECT, 2019
** my_printf.c
** File description:
** Find a substring in a string
*/

#include <stddef.h>
#include <stdbool.h>

static bool my_is_to_find(char *str, int i, char const *to_find);

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;

    while (str[i] != '\0') {
        if (my_is_to_find(str, i, to_find))
            return (&str[i]);
        i = i + 1;
    }
    return (NULL);
}

static bool my_is_to_find(char *str, int i, char const *to_find)
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
