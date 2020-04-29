/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Header file for libmy.a
*/

#ifndef __DEF_MY__
    #define __DEF_MY__

    #include <stdarg.h>
    #include <stdbool.h>

    #define MY_EXIT_SUCCESS     0
    #define MY_EXIT_FAILURE     84

    #define BINARY_MAX_LEN                    32
    #define UINT_MAX_LEN                      10
    #define LLINT_MAX_LEN                     19
    #define LLUINT_MAX_LEN                    20
    #define OCTAL_CHAR_MAX_LEN                4
    #define OCTAL_UINT_MAX_LEN                11
    #define OCTAL_LLUINT_MAX_LEN              22
    #define HEXA_MAX_LEN                      8
    #define LLU_HEXA_MAX_LEN                  16
    #define DOUBLE_MAX_LEN                    316
    #define HEXA_LOWER                        "0123456789abcdef"
    #define HEXA_UPPER                        "0123456789ABCDEF"
    #define UINT_MAX_STR                      "4294967295"
    #define CONVERTERS_SPECIFIERS             "bcdisSuxX%opP"
    #define CONVERTERS_SPECIFIERS_NB          13
    #define INT_CONVERTERS                    "diouxX"
    #define SIGNED_INT_CONVERTERS             "di"
    #define UNSIGNED_INT_CONVERTERS           "ouxX"
    #define LENGTH_MODIFIERS_NB               4
    #define FLAGS                          "#0- +"
    #define FLAGS_NB                       5

    typedef struct converter_specifier {
        char symbol;
        char *(*convertion)(va_list args);
    } converter_t;

    converter_t *my_get_converter(char **format);
    converter_t *my_get_converter_specifier(char my_char);

    typedef struct format {
        char *format;
        char *org_format;
        unsigned int width;
        int precision;
        converter_t *converter;
        bool is_right_padded;
    } format_t;

    typedef struct flag {
        char symbol;
        void (*convertion)(format_t *format, char *converted,
                            char **flags_output);
    } flag_t;

    typedef struct hash_flag {
        char symbol;
        char *to_put;
    } hash_flag_t;

    bool my_is_flag(char const my_char);
    flag_t *my_get_flag(char const symbol);

    void my_hash_flag_convertion(format_t *, char *, char **);
    void my_space_flag_convertion(format_t *, char *, char **);
    void my_zero_flag_convertion(format_t *, char *, char **);
    void my_minus_flag_convertion(format_t *, char *, char **);
    void my_plus_flag_convertion(format_t *, char *, char **);

    typedef struct length_modifier {
        char *symbols;
        char *(*convertion)(va_list args);
    } length_modifier_t;
    typedef length_modifier_t lm_t;

    lm_t *my_get_length_modifier(char **str, converter_t *converter);

    void my_putchar(char my_char);
    void my_putstr(char const *str);
    void my_puterr(char const *str);
    void my_str_rotate(char *str, int index);
    void my_strarr_rotate(char **arr, int index);
    void my_strarr_remove_empty(char **arr);
    void my_free_str_array(char **arr);

    bool my_is_converter(char const my_char);
    bool my_char_is_digit(char const my_char);
    bool my_char_is_alpha(char my_char);
    bool my_char_is_alpha_lower(char my_char);
    bool my_char_is_alpha_upper(char my_char);
    bool my_char_is_alphanum(char const my_char);
    bool my_is_flag(char const my_char);
    bool my_is_int_converter(char my_char);
    bool my_is_printable(char const my_char);
    bool my_is_int_converter(char my_char);
    bool my_is_int_signed_converter(char my_char);
    bool my_is_int_unsigned_converter(char my_char);
    bool my_str_is_alpha(char const *str);
    bool my_str_is_alphanum(char const *str);
    bool my_str_isnum(char const *str);
    bool my_str_isnum_pos(char const *str);
    bool my_str_isnum_neg(char const *str);
    bool my_str_beg(char const *src, char const *beg);
    bool my_str_contains(char const *str, char const *to_find);
    bool my_str_contains_char(char const *str, char const c);
    bool my_str_ends(char const *str, char const *end);
    bool my_str_ends_char(char const *str, char const end);
    bool my_str_is_empty(char const *str);

    int my_printf(const char *restrict format, ...);
    int my_eprintf(const char *restrict format, ...);
    int my_atoi(char const *str);
    int my_intlen(int nb);
    int my_strcmp(char const *s1, char const *s2);
    int my_get_precision(char **format);
    int my_str_get_index(char const *str, char const to_find);
    unsigned int my_count_char(char const *str, char const to_count);
    unsigned int my_count_until_sep(char const *str, char const sep);
    unsigned int my_strlen(char const *str);
    unsigned int my_strarr_len(char **arr);
    unsigned int my_get_width_field(char **format);
    unsigned int my_strnum_to_uint(char const *strnum);

    char *my_get_formatted_output(format_t *format, va_list args);
    char *my_str_delim(char const *str, char const beg, char const end);
    char *my_revstr(char *str);
    char *my_clean_str(char *str);
    char *my_str_to_lower(char *str);
    char *my_char_to_octal(char my_char);
    char *my_strcat(char *dest, char const *src);
    char *my_strcpy(char *dest, char const *src);
    char *my_strdup(char const *src);
    char *my_strdupcat(char const *s1, char const *s2);
    char *my_strstr(char const *str, char const *to_find);

    char **my_str_to_word_array(char const *str, char const sep);

    char *my_char_to_str(va_list args);
    char *my_arg_to_str(va_list args);
    char *my_percentage_to_str(va_list args);
    char *my_np_to_str(va_list args);
    char *my_int_to_strnum(va_list arg);
    char *my_uint_to_strnum(va_list arg);
    char *my_decimal_to_binary(va_list args);
    char *my_decimal_to_octal(va_list args);
    char *my_decimal_to_hexa_lower(va_list args);
    char *my_decimal_to_hexa_upper(va_list args);
    char *my_ptr_to_hexa_lower(va_list args);
    char *my_ptr_to_hexa_upper(va_list args);

    char *my_llint_to_strnum(va_list args);
    char *my_lluint_to_strnum(va_list args);
    char *my_lluint_to_octal(va_list args);
    char *my_lluint_to_hexa_lower(va_list args);
    char *my_lluint_to_hexa_upper(va_list args);
#endif