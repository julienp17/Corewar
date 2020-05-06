/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_hash_convertion
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

static hash_flag_t *get_hash_flag(format_t *format, char *converted);
static void my_hash_octal_convertion(hash_flag_t *flag, char **flags_output);
static void my_hash_hexa_convertion(hash_flag_t *flag, char **flags_output);

void my_hash_flag_convertion(format_t *format, char *converted,
                            char **flags_output)
{
    hash_flag_t *flag = get_hash_flag(format, converted);

    if (!flag)
        return;
    if (flag->symbol == 'o')
        my_hash_octal_convertion(flag, flags_output);
    else
        my_hash_hexa_convertion(flag, flags_output);
}

static void my_hash_octal_convertion(hash_flag_t *flag, char **flags_output)
{
    if ((*flags_output)[0]) {
        (*flags_output)[my_strlen(*flags_output) - 1] = flag->to_put[0];
    } else {
        (*flags_output)[0] = flag->to_put[0];
        (*flags_output)[1] = '\0';
    }
}

static void my_hash_hexa_convertion(hash_flag_t *flag, char **flags_output)
{
    if ((*flags_output)[0]) {
        (*flags_output)[my_strlen(*flags_output) - 2] = flag->to_put[0];
        (*flags_output)[my_strlen(*flags_output) - 1] = flag->to_put[1];
    } else {
        (*flags_output)[0] = flag->to_put[0];
        (*flags_output)[1] = flag->to_put[1];
        (*flags_output)[2] = '\0';
    }
}

static hash_flag_t *get_hash_flag(format_t *format, char *converted)
{
    hash_flag_t *flag = malloc(sizeof(*flag));
    hash_flag_t const flags[] = {
        {'o', "0"},
        {'x', "0x"},
        {'X', "0X"}
    };

    if (my_strcmp(converted, "0") == 0)
        return (NULL);
    for (unsigned int i = 0 ; i < 3 ; i = i + 1)
        if (format->converter->symbol == flags[i].symbol) {
            flag->symbol = flags[i].symbol;
            flag->to_put = flags[i].to_put;
            return (flag);
        }
    return (NULL);
}