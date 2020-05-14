/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_zero_flag_convertion
*/

#include <stddef.h>
#include "my.h"

void my_zero_flag_convertion(format_t *format, char *converted,
                            char **flags_output)
{
    unsigned int i = 0;

    (void)converted;
    if (my_strstr(format->format, "-") != NULL || format->precision > 0)
        return;
    if (my_is_int_converter(format->converter->symbol)) {
        if ((*flags_output)[i] == '+' || my_strstr(format->format, " ") != NULL)
            i++;
        while ((*flags_output)[i]) {
            (*flags_output)[i] = '0';
            i++;
        }
        (*flags_output)[i] = '\0';
    }
}