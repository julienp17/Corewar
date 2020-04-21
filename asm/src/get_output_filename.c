/*
** EPITECH PROJECT, 2020
** Corewar Assembler
** File description:
** Get the output filename of given file
*/

#include "asm.h"
#include "my.h"

char *get_output_filename(char const *filename)
{
    char *output_filename = NULL;
    unsigned int len = 0;

    if (!my_str_ends(filename, ASM_EXT))
        return (my_strdupcat(filename, COR_EXT));
    len = my_strlen(filename) - my_strlen(ASM_EXT) + my_strlen(COR_EXT);
    output_filename = malloc(sizeof(char) * (len + 1));
    if (output_filename == NULL) {
        my_puterr("Coudln't allocate memory for output_filename\n");
        return (NULL);
    }
    output_filename = my_strcpy(output_filename, filename);
    len -= my_strlen(COR_EXT);
    output_filename[len] = '\0';
    output_filename = my_strcat(output_filename, COR_EXT);
    return (output_filename);
}