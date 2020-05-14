/*
** EPITECH PROJECT, 2020
** asm
** File description:
** my_str_delim
*/

#include <stdlib.h>
#include "my.h"

static char *delim_str(char const *str, int i, int j);

char *my_str_delim(char const *str, char const beg, char const end)
{
    int i = 0;
    int j = 0;

    while (str[i] && str[i] != beg)
        i++;
    if (str[i] == '\0')
        return (NULL);
    j = i + 1;
    while (str[j] && str[j] != end)
        j++;
    if (str[j] == '\0')
        return (NULL);
    return (delim_str(str, i, j));
}

static char *delim_str(char const *str, int i, int j)
{
    char *delim = NULL;
    int k = 0;

    delim = malloc(sizeof(char) * ((j - i) + 1));
    if (delim == NULL) {
        my_puterr("Couldn't allocate memory for my_str_delim\n");
        return (NULL);
    }
    for (k = 0 ; k < (j - i) - 1 ; k++)
        delim[k] = str[i + k + 1];
    delim[k] = '\0';
    return (delim);
}