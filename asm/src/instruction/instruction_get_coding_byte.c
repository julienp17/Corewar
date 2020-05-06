/*
** EPITECH PROJECT, 2020
** Corewar ASM
** File description:
** instruction_get_coding_byte
*/

#include "instruction.h"
#include "asm.h"

unsigned char instruction_get_coding_byte(char **args)
{
    unsigned char coding_byte = 0;
    int arg_type = 0;
    int i = 0;

    for (i = 0 ; args[i] ; i++) {
        arg_type = argument_get_type(args[i]);
        arg_type -= (arg_type == T_IND);
        coding_byte = (coding_byte << 2) + arg_type;
    }
    for (; i < MAX_ARGS_NUMBER ; i++)
        coding_byte <<= 2;
    return (coding_byte);
}
