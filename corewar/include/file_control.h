/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** file_read
*/

#ifndef FILE_READ_H_
    #define FILE_READ_H_

    #include <sys/types.h>

    #define READ_SIZE   1024

    typedef struct buffer {
        ssize_t size;
        void *buf;
    } buffer_t;

    ssize_t get_file_size(char const *filename);
    int buffer_fill_from_file(char const *filename, buffer_t *buf);
#endif
