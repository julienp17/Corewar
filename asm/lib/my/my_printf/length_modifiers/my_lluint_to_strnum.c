/*
** EPITECH PROJECT, 2019
** C Pool EvalExpr
** File description:
** Converts an integer into a numerical string
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

char *my_lluint_to_strnum(va_list args)
{
    int i = 0;
    long long unsigned int nb = va_arg(args, long long unsigned int);
    char *strnum = malloc(sizeof(char) * (LLUINT_MAX_LEN + 1));

    if (nb == 0)
        return ("0");
    while (nb != 0) {
        strnum[i] = nb % 10 + '0';
        nb = nb / 10;
        i = i + 1;
    }
    strnum[i] = '\0';
    return (my_revstr(strnum));
}