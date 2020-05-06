/*
** EPITECH PROJECT, 2019
** my_is_alpha_upper.c
** File description:
** Returns 1 if char is alpha and upper, 0 otherwise
*/

#include <stdbool.h>

bool my_char_is_alpha_upper(char my_char)
{
    return (my_char >= 'A' && my_char <= 'Z');
}
