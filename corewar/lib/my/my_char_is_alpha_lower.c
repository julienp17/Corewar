/*
** EPITECH PROJECT, 2019
** my_is_alpha_lower.c
** File description:
** Returns 1 if char is alpha and lower, 0 otherwise
*/

#include <stdbool.h>

bool my_char_is_alpha_lower(char my_char)
{
    return (my_char >= 'a' && my_char <= 'z');
}
