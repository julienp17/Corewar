/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Converts a pointer to hexadecimal upper notation
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

char *my_ptr_to_hexa_upper(va_list args)
{
    unsigned long int address = va_arg(args, unsigned long int);
    char base[] = HEXA_UPPER;
    char *hexa = malloc(sizeof(char) * (HEXA_MAX_LEN + 1));
    int digit = 0;
    int i = 0;

    if (address == 0)
        return ("(nil)");
    for (i = 0 ; address > 0 ; i = i + 1) {
        digit = address % 16;
        hexa[i] = base[digit];
        address = address / 16;
    }
    hexa[i++] = 'x';
    hexa[i++] = '0';
    hexa[i] = '\0';
    return (my_revstr(hexa));
}