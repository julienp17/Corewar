/*
** EPITECH PROJECT, 2020
** asm
** File description:
** my_strarr_rotate
*/

void my_strarr_rotate(char **arr, int index)
{
    for (int i = index ; arr[i] ; i++)
        arr[i] = arr[i + 1];
}