/*
** EPITECH PROJECT, 2020
** tmp_n4s
** File description:
** my_str_beg
*/

#include <stdbool.h>

bool my_str_beg(char const *src, char const *beg)
{
    if (beg[0] == '\0')
        return (false);
    for (unsigned int i = 0 ; beg[i] ; i++)
        if (beg[i] != src[i])
            return (false);
    return (true);
}