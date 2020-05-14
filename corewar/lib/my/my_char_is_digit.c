/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Returns true if char is digit, false otherwise
*/

#include <stdbool.h>

bool my_char_is_digit(char const my_char)
{
    return (my_char >= '0' && my_char <= '9');
}