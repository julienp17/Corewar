/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_space_flag_convertion
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

static bool can_convert(format_t *format, char *converted);

void my_space_flag_convertion(format_t *format, char *converted,
                            char **flags_output)
{
    if (my_strstr(format->format, "+") != NULL)
        return;
    if (can_convert(format, converted)) {
        if ((*flags_output)[0]) {
            (*flags_output)[my_strlen(*flags_output) - 1] = ' ';
        } else {
            (*flags_output)[0] = ' ';
            (*flags_output)[1] = '\0';
        }
    }
}

static bool can_convert(format_t *format, char *converted)
{
    if (my_is_int_signed_converter(format->converter->symbol))
        if (my_str_isnum_pos(converted))
            return (true);
    return (false);
}