/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Converts a char to a string
*/

#include <stdarg.h>
#include <stdlib.h>

char *my_char_to_str(va_list args)
{
    char *str = malloc(sizeof(char) * 2);

    str[0] = (char)va_arg(args, int);
    str[1] = '\0';
    return (str);
}