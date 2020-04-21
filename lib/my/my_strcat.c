/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** cat 2 strings
*/

#include "stdlib.h"

int my_strlenbis(char const *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i = i+1;
    }
    return (i);
}

char *my_strcat( char *s1, char *s2)
{
    int size1 = my_strlenbis(s1);
    int size2 = my_strlenbis(s2);
    char *str = malloc (sizeof(char) * size1 + size2 + 1);
    int i = 0;
    int a = 0;

    if (s1 == NULL)
        return s2;
    while (s1[i] != '\0') {
        str[i] = s1[i];
        i++;
    }
    while (s2[a] != '\0') {
        str[i] = s2[a];
        i++;
        a++;
    }
    return str;
}
