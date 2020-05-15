/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Reproduce the printf function in accordance to the C99 standard
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

static int my_print_tokens(char **format_string, va_list args);
static char *my_get_formatted_string(char *format, va_list args);
static char *my_get_format(char const *format_string);
static format_t *my_init_format(char *org_format);

int my_eprintf(char const *str, ...)
{
    va_list args;
    char *format_string = my_strdup(str);
    int chars_written = 0;

    va_start(args, str);
    while (format_string[0])
        chars_written = chars_written + my_print_tokens(&format_string, args);
    va_end(args);
    return (chars_written);
}

static int my_print_tokens(char **format_string, va_list args)
{
    char *format = NULL;
    char *formatted_string = NULL;
    int chars_written = 0;

    if ((*format_string)[0] == '%') {
        format = my_get_format(*format_string);
        (*format_string) = (*format_string) + my_strlen(format);
        formatted_string = my_get_formatted_string(format, args);
        chars_written = chars_written + my_strlen(formatted_string);
        my_puterr(formatted_string);
    } else {
        write(STDERR_FILENO, &((*format_string)[0]), 1);
        (*format_string) = (*format_string) + 1;
        chars_written = chars_written + 1;
    }
    return (chars_written);
}

static char *my_get_format(char const *format_string)
{
    char *format = malloc(sizeof(char) * (my_strlen(format_string) + 1));
    int i = 0;

    format[0] = '%';
    format_string = format_string + 1;
    while (format_string[i] && !my_is_converter(format_string[i])) {
        format[i + 1] = format_string[i];
        i = i + 1;
    }
    if (my_is_converter(format_string[i])) {
        format[i + 1] = format_string[i];
        i = i + 1;
    }
    format[i + 1] = '\0';
    return (format);
}

static char *my_get_formatted_string(char *org_format, va_list args)
{
    format_t *format = NULL;

    if (!my_is_converter(org_format[my_strlen(org_format) - 1]))
        return (org_format);
    format = my_init_format(org_format);
    if (format->converter->symbol == '%')
        return ("%");
    if (format->precision == -1)
        return (format->org_format);
    return (my_get_formatted_output(format, args));
}

static format_t *my_init_format(char *org_format)
{
    format_t *format = malloc(sizeof(*format));

    format->format = my_strdup(org_format + 1);
    format->org_format = my_strdup(org_format);
    format->converter = my_get_converter(&(format->format));
    format->precision = my_get_precision(&(format->format));
    format->width = my_get_width_field(&(format->format));
    format->is_right_padded = true;
    return (format);
}