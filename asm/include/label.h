/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** Label structure
*/

#ifndef LABEL_H_
    #define LABEL_H_

    #include <stdint.h>
    #include <stdlib.h>

    typedef struct label {
        char *name;
        int16_t offset;
    } label_t;

    label_t *label_create(char const *name, int16_t offset);
#endif
