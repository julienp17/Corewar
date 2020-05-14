/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Returns a string with non printable characters as octal base
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

int my_strlen_np(char const *str);

char *my_np_to_str(va_list args)
{
    char *org_str = va_arg(args, char *);
    char *str = malloc(sizeof(char) * (my_strlen_np(org_str) + 1));
    unsigned int i = 0;
    unsigned int j = 0;

    while (org_str[j]) {
        if (!my_is_printable(org_str[j])) {
            str[i] = '\0';
            str = my_strcat(str, my_char_to_octal(org_str[j]));
            i = i + 3;
        } else {
            str[i] = org_str[j];
        }
        i = i + 1;
        j = j + 1;
    }
    return (str);
}

int my_strlen_np(char const *str)
{
    int len = 0;

    for (int i = 0 ; str[i] ; i = i + 1) {
        if (!my_is_printable(str[i]))
            len = len + 4;
        else
            len = len + 1;
    }
    return (len);
}