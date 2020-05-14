/*
** EPITECH PROJECT, 2020
** asm
** File description:
** my_str_get_index
*/

int my_str_get_index(char const *str, char const to_find)
{
    for (int i = 0 ; str[i] ; i++)
        if (str[i] == to_find)
            return (i);
    return (-1);
}