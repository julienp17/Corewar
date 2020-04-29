/*
** EPITECH PROJECT, 2019
** C Pool EvalExpr
** File description:
** Converts an integer into a numerical string
*/

#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include "my.h"

static bool check_is_neg(long long int *nb);

char *my_llint_to_strnum(va_list args)
{
    long long int nb = va_arg(args, long long int);
    int i = 0;
    bool is_neg = false;
    char *strnum = malloc(sizeof(char) * (LLINT_MAX_LEN + 2));

    if (nb == 0)
        return ("0");
    if (nb == LLONG_MIN)
        return ("-9223372036854775808");
    is_neg = check_is_neg(&nb);
    for (; nb != 0 ; i = i + 1) {
        strnum[i] = nb % 10 + '0';
        nb = nb / 10;
    }
    if (is_neg) {
        strnum[i] = '-';
        i = i + 1;
    }
    strnum[i] = '\0';
    return (my_revstr(strnum));
}

static bool check_is_neg(long long int *nb)
{
    if (*nb < 0) {
        *nb = *nb * -1;
        return (true);
    }
    return (false);
}