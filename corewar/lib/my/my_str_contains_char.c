/*
** EPITECH PROJECT, 2020
** asm
** File description:
** my_str_contains_char
*/

#include <stdbool.h>

bool my_str_contains_char(char const *str, char const c)
{
    unsigned int i = 0;

    while (str[i] && str[i] != c)
        i++;
    return (str[i] == c);
}