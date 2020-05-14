/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Format structure
*/

#include <stdlib.h>
#include "my.h"

converter_t *my_get_converter(char **format)
{
    converter_t *converter = NULL;
    length_modifier_t *length_modifier = NULL;
    char specifier = (*format)[my_strlen(*format) - 1];

    (*format)[my_strlen(*format) - 1] = '\0';
    converter = my_get_converter_specifier(specifier);
    length_modifier = my_get_length_modifier(format, converter);
    if (length_modifier) {
        (*format)[my_strlen(*format) - my_strlen(length_modifier->symbols)] = 0;
        converter->convertion = length_modifier->convertion;
        free(length_modifier);
    }
    return (converter);
}

converter_t *my_get_converter_specifier(char my_char)
{
    int i = 0;
    converter_t *converter = malloc(sizeof(*converter));
    converter_t const converters[] = {
        {'b', &my_decimal_to_binary},
        {'c', &my_char_to_str},
        {'d', &my_int_to_strnum}, {'i', &my_int_to_strnum},
        {'s', &my_arg_to_str}, {'S', &my_np_to_str},
        {'u', &my_uint_to_strnum},
        {'o', &my_decimal_to_octal},
        {'x', &my_decimal_to_hexa_lower}, {'X', &my_decimal_to_hexa_upper},
        {'p', &my_ptr_to_hexa_lower}, {'P', &my_ptr_to_hexa_upper},
        {'%', NULL}
    };

    while (i < CONVERTERS_SPECIFIERS_NB && my_char != converters[i].symbol)
        i = i + 1;
    converter->symbol = converters[i].symbol;
    converter->convertion = converters[i].convertion;
    return (converter);
}