/*
** EPITECH PROJECT, 2020
** asm
** File description:
** my_str_end_char
*/

#include <stddef.h>
#include <stdbool.h>
#include "my.h"

bool my_str_ends_char(char const *str, char const end)
{
    unsigned int i = 0;

    while (str[i])
        i++;
    if (i == 0)
        return (end == '\0');
    return (end == str[i - 1]);
}