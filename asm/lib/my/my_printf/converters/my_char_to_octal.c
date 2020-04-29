/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Converts an unsigned integer into a octal string
*/

#include <stdlib.h>
#include "my.h"

char *my_char_to_octal(char my_char)
{
    char *octal = malloc(sizeof(char) * (OCTAL_CHAR_MAX_LEN + 1));

    octal[0] = '\\';
    for (int i = 3 ; i > 0 ; i = i - 1) {
        octal[i] = my_char % 8 + '0';
        my_char = my_char / 8;
    }
    octal[4] = '\0';
    return (octal);
}