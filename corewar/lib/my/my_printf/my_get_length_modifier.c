/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Format structure
*/

#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "my.h"

static length_modifier_t *get_h_or_hh_length_modifier(char *rev_str,
                                                    converter_t *converter);
static length_modifier_t *get_l_or_ll_length_modifier(char *rev_str,
                                                    converter_t *converter);
static char *(*get_unsigned_convertion(char symbol))(va_list);

length_modifier_t *my_get_length_modifier(char **format, converter_t *converter)
{
    char *str = my_strdup((*format));

    if (!my_is_int_converter(converter->symbol))
        return (NULL);
    str = my_revstr(str);
    if (str[0] == 'h')
        return (get_h_or_hh_length_modifier(str, converter));
    else if (str[0] == 'l')
        return (get_l_or_ll_length_modifier(str, converter));
    return (NULL);
}

static length_modifier_t *get_h_or_hh_length_modifier(char *rev_str,
                                                    converter_t *converter)
{
    length_modifier_t *length_modifier = malloc(sizeof(length_modifier));

    if (rev_str[1] == 'h')
        length_modifier->symbols = "hh";
    else
        length_modifier->symbols = "h";
    length_modifier->convertion = converter->convertion;
    return (length_modifier);
}

static length_modifier_t *get_l_or_ll_length_modifier(char *rev_str,
                                                    converter_t *converter)
{
    length_modifier_t *length_modifier = malloc(sizeof(length_modifier));

    if (rev_str[1] == 'l')
        length_modifier->symbols = "ll";
    else
        length_modifier->symbols = "l";
    if (my_is_int_signed_converter(converter->symbol)) {
        length_modifier->convertion = &my_llint_to_strnum;
        return (length_modifier);
    }
    length_modifier->convertion = get_unsigned_convertion(converter->symbol);
    return (length_modifier);
}

static char *(*get_unsigned_convertion(char symbol))(va_list)
{
    char *(*convertion)(va_list) = NULL;

    switch (symbol) {
    case 'u':
        convertion = &my_lluint_to_strnum;
        break;
    case 'o':
        convertion = &my_lluint_to_octal;
        break;
    case 'x':
        convertion = &my_lluint_to_hexa_lower;
        break;
    case 'X':
        convertion = &my_lluint_to_hexa_upper;
        break;
    }
    return (convertion);
}