/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Returns a string in an va_list
*/

#include <stdarg.h>
#include <stdlib.h>

char *my_arg_to_str(va_list args)
{
    return (va_arg(args, char *));
}