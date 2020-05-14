/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Returns true if char is digit or alpha
*/

#include <stdbool.h>

bool my_char_is_digit(char const my_char);
bool my_char_is_alpha(char my_char);

bool my_char_is_alphanum(char const my_char)
{
    return (my_char_is_alpha(my_char) || my_char_is_digit(my_char));
}