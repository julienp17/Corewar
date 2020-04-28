/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** File control
*/

#ifndef FILE_CONTROL_H_
    #define FILE_CONTROL_H_

    #include <sys/types.h>

    #define READ_SIZE       1024

    ssize_t get_file_size(char const *filename);
    char *get_file_buffer(char const *file_path);
    char **get_file_lines(char const *file_path);
    char *get_pretty_filename(char *ugly_filename);
#endif