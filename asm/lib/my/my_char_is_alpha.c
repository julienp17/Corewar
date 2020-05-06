/*
** EPITECH PROJECT, 2019
** my_is_alpha.c
** File description:
** Returns 1 if char is alphabetical, 0 otherwise
*/

#include <stdbool.h>

bool my_char_is_alpha_lower(char my_char);
bool my_char_is_alpha_upper(char my_char);

bool my_char_is_alpha(char my_char)
{
    return (my_char_is_alpha_lower(my_char) || my_char_is_alpha_upper(my_char));
}
