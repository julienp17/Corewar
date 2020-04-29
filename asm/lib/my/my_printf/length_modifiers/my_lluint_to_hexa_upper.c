/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Converts a long long unsigned integer into an hexadecimal uppercase string
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

char *my_lluint_to_hexa_upper(va_list args)
{
    long long unsigned int decimal = va_arg(args, long long unsigned int);
    char base[] = HEXA_UPPER;
    char *hexa = malloc(sizeof(char) * (LLU_HEXA_MAX_LEN + 1));
    int digit = 0;

    if (decimal == 0)
        return ("0");
    for (int i = 0 ; decimal > 0 ; i = i + 1) {
        digit = decimal % 16;
        hexa[i] = base[digit];
        decimal = decimal / 16;
    }
    return (my_revstr(hexa));
}