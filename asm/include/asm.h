/*
** EPITECH PROJECT, 2020
** Corewar Assembler
** File description:
** Assembler header file
*/

#ifndef ASM_H_
    #define ASM_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdint.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include "op.h"
    #include "label.h"

    #define ASM_HELP   \
    "USAGE\n"                                                                  \
    "       ./asm file_name[.s]\n"                                             \
    "\n"                                                                       \
    "DESCRIPTION\n"                                                            \
    "       file_name       file in assembly language to be converted into "   \
    "file_name.cor, an\n"                                                      \
    "                       executable in the Virtual Machine.\n"

    #define ASM_EXT         ".s"
    #define COR_EXT         ".cor"
    #define REGISTER_CHAR   'r'

    typedef unsigned int uint;

    int assemble(char const *filename);

    char **parse_instructions_from_file(char const *filename);
    char **parse_instruction(char const *instruction);

    bool instruction_is_correct(char const *instruction);

    int encode_to_file(char const *output_filename, char **instructions);
    int encode(int fd, char **instructions);
    int encode_header(int fd, char **instructions);
    ssize_t encode_instruction(int fd, char const *instruction, label_t **labels, ssize_t current_offset);

    bool arg_is_index(op_t op);
    op_t get_op_by_name(char const *name);
    int get_argument_type(char const *arg);
    int get_argument_size(op_t op, char const *arg);
    int16_t swap_int16(int16_t val);
    int32_t swap_int32(int32_t val);
#endif