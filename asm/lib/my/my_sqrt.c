/*
** EPITECH PROJECT, 2020
** sqrt
** File description:
** return a float root
*/

#include <stdio.h>

float my_sqrt(float nb, float min, float max)
{
    float mid = 0;

    while (max - min > 1) {
        mid = (min + max) / 2;
        if (mid * mid > nb)
            max = mid;
        else {
            min = mid;
        }
    }
    return max;
}