/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Returns true if char is printable, false otherwise
*/

#include <stdbool.h>

bool my_is_printable(char const my_char)
{
    return (my_char >= 32 && my_char < 127);
}