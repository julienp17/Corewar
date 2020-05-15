/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Returns true if the given char is a format flag, false otherwise
*/

#include <stdbool.h>
#include "my.h"

bool my_is_flag(char const my_char)
{
    char const flags[] = FLAGS;

    for (int i = 0 ; flags[i] ; i = i + 1) {
        if (my_char == flags[i])
            return (true);
    }
    return (false);
}