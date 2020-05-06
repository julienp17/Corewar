/*
** EPITECH PROJECT, 2020
** asm
** File description:
** my_strarr_put
*/

#include "my.h"

void my_strarr_put(char **arr)
{
    for (unsigned int i = 0 ; arr[i] ; i++) {
        my_putstr(arr[i]);
        my_putchar('\n');
    }
}