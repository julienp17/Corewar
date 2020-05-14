/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Get flags
*/

#include <stdlib.h>
#include "my.h"

flag_t *my_get_flag(char symbol)
{
    flag_t *flag = malloc(sizeof(*flag));
    flag_t const flags[] = {
        {'#', &my_hash_flag_convertion},
        {' ', &my_space_flag_convertion},
        {'0', &my_zero_flag_convertion},
        {'-', &my_minus_flag_convertion},
        {'+', &my_plus_flag_convertion}
    };

    for (unsigned int i = 0 ; i < FLAGS_NB ; i++) {
        if (symbol == flags[i].symbol) {
            flag->symbol = flags[i].symbol;
            flag->convertion = flags[i].convertion;
            return (flag);
        }
    }
    return (NULL);
}