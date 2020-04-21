/*
** EPITECH PROJECT, 2019
** Pushswap
** File description:
** Header file for libmy.a
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdbool.h>

    void my_putchar(char c);
    void my_putstr(char const *str);
    void my_puterr(char const *str);
    void my_put_nbr(int nb);
    void my_free_str_array(char **arr);
    void my_strarr_remove_empty(char **arr);
    void my_strarr_rotate(char **arr, int index);

    bool my_char_is_num(char const c);
    bool my_str_isnum_pos(char const *str);
    bool my_str_contains(char const *str, char const *to_find);
    bool my_str_ends(char const *str, char const *end);
    bool my_str_is_empty(char const *str);

    int my_atoi(char const *str);
    int my_strcmp(char const *s1, char const *s2);
    int my_str_get_index(char const *str, char const to_find);
    unsigned int my_intlen(int nb);
    unsigned int my_strarr_len(char **arr);
    unsigned int my_strlen(char const *str);
    unsigned int my_count_char(char const *str, char const to_count);
    unsigned int my_count_until_sep(char const *str, char const sep);

    char *my_strcpy(char *dest, char const *src);
    char *my_strdup(char const *src);
    char *my_strdupcat(char const *s1, char const *s2);
    char *my_revstr(char *str);
    char *my_int_to_strnum(int nb);
    char *my_clean_str(char *str);
    char **my_str_to_word_array(char const *str, char const sep);
    char *my_strcat( char *s1, char *s2);

    float my_sqrt(float nb, float min, float max);

#endif
