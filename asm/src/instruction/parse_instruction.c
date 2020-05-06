/*
** EPITECH PROJECT, 2020
** asm
** File description:
** Parse the instructions of an assembler file
*/

#include "asm.h"
#include "file_control.h"
#include "my.h"

char **parse_instructions_from_file(char const *filename)
{
    char **instructions = NULL;
    int comment_index = 0;

    instructions = get_file_lines(filename);
    if (instructions == NULL)
        return (NULL);
    for (unsigned int i = 0 ; instructions[i] ; i++) {
        comment_index = my_str_get_index(instructions[i], COMMENT_CHAR);
        if (comment_index >= 0)
            instructions[i][comment_index] = '\0';
        instructions[i] = my_clean_str(instructions[i]);
    }
    return (instructions);
}

char **parse_instruction(char const *instruction)
{
    char **tokens = NULL;
    char *instruction_cpy = NULL;

    instruction_cpy = my_strdup(instruction);
    for (unsigned int i = 0 ; instruction_cpy[i] ; i++)
        if (instruction_cpy[i] == SEPARATOR_CHAR)
            instruction_cpy[i] = ' ';
    instruction_cpy = my_clean_str(instruction_cpy);
    tokens = my_str_to_word_array(instruction_cpy, ' ');
    free(instruction_cpy);
    return (tokens);
}