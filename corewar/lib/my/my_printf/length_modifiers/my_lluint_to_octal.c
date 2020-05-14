/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Converts a long long unsigned integer into an octal string
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

char *my_lluint_to_octal(va_list args)
{
    long long unsigned int decimal = va_arg(args, long long unsigned int);
    char *octal = malloc(sizeof(char) * (OCTAL_LLUINT_MAX_LEN + 1));
    int digit = 0;

    if (decimal == 0)
        return ("0");
    for (int i = 0 ; decimal > 0 ; i = i + 1) {
        digit = decimal % 8;
        octal[i] = digit + '0';
        decimal = decimal / 8;
    }
    return (my_revstr(octal));
}