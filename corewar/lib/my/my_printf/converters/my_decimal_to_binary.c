/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Converts an unsigned integer into a binary string
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

char *my_decimal_to_binary(va_list args)
{
    unsigned int decimal = va_arg(args, unsigned int);
    char *binary = malloc(sizeof(char) * (BINARY_MAX_LEN + 1));
    int digit = 0;
    int i = 0;

    if (decimal == 0)
        return ("0");
    for (i = 0 ; decimal > 0 ; i = i + 1) {
        digit = decimal % 2;
        binary[i] = digit + '0';
        decimal = decimal / 2;
    }
    binary[i] = '\0';
    return (my_revstr(binary));
}