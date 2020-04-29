/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** Returns a newly allocated label structure
*/

#include "label.h"
#include "my.h"

label_t *label_create(char const *name, int16_t offset)
{
    label_t *label = NULL;

    label = malloc(sizeof(label_t));
    if (label == NULL) {
        my_puterr("Couldn't allocate memory for label struct.\n");
        return (NULL);
    }
    label->name = my_strdup(name);
    label->offset = offset;
    return (label);
}