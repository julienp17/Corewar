/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Get flags
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "my.h"

static char *init_converted_output(format_t *format, char const *converted);
static char *init_formatted_output(format_t *format, char const *converter);

char *my_get_formatted_output(format_t *format, va_list args)
{
    char *converted = format->converter->convertion(args);
    char *converted_output = init_converted_output(format, converted);
    char *formatted_output = init_formatted_output(format, converted);
    flag_t *flag;
    unsigned int i = 0;

    while (format->format[i] != '\0' && format->format[i] != 1) {
        if (!my_is_flag(format->format[i]))
            return (format->org_format);
        flag = my_get_flag(format->format[i]);
        flag->convertion(format, converted_output, &formatted_output);
        i++;
    }
    if (format->is_right_padded)
        return (my_strcat(formatted_output, converted_output));
    return (my_strcat(converted_output, formatted_output));
}

static char *init_converted_output(format_t *format, char const *converted)
{
    unsigned int len = my_strlen(converted) + format->width + 3;
    char *converted_output = malloc(sizeof(char) * len);

    converted_output = my_strcpy(converted_output, converted);
    return (converted_output);
}

static char *init_formatted_output(format_t *format, char const *converted)
{
    unsigned int i = 0;
    unsigned int converted_len = my_strlen(converted);
    unsigned int len = 0;
    char *str = malloc(sizeof(char) * (format->width + converted_len + 3));

    if (format->width > converted_len)
        len = format->width - converted_len;
    while (i < len) {
        str[i] = ' ';
        i++;
    }
    str[i] = '\0';
    return (str);
}