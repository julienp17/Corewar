/*
** EPITECH PROJECT, 2019
** C Pool EvalExpr
** File description:
** Converts an integer into a numerical string
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

char *my_uint_to_strnum(va_list args)
{
    int i = 0;
    unsigned int nb = va_arg(args, unsigned int);
    char *strnum = malloc(sizeof(char) * (UINT_MAX_LEN + 1));

    if (nb == 0)
        return ("0");
    for (; nb != 0 ; i = i + 1) {
        strnum[i] = nb % 10 + '0';
        nb = nb / 10;
    }
    strnum[i] = '\0';
    return (my_revstr(strnum));
}