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
    #include "instruction.h"

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

    typedef struct assembler {
        char *input_filename;
        char **lines;
        int line;
        header_t header;
        instruction_t **instructions;
        uint nb_instructions;
    } asm_t;

    asm_t *asm_create(char const *filename);
    void asm_destroy(asm_t *assembler);

    int assemble(char const *filename);
    bool asm_has_an_instruction(asm_t *asb);

    int asm_fill(asm_t *assembler);
    int asm_fill_program_name(asm_t *asb, char const *line);
    int asm_fill_comment(asm_t *asb, char const *line);
    int asm_fill_instructions_meta(asm_t *asb);
    int asm_fill_instruction_value(asm_t *asb, char const *line);

    int asm_encode(asm_t *assembler);
    int asm_encode_header(int fd, header_t *header);
    void asm_puterr(asm_t *assembler, char const *error_str);

    op_t op_get_by_name(char const *name);
    bool op_has_coding_byte(op_t op);

    char **parse_instructions_from_file(char const *filename);
    char **parse_instruction(char const *instruction);
    bool instruction_is_correct(asm_t *asb, char const *instruction);
    int16_t instruction_get_size(char const *instruction);
    uchar instruction_get_coding_byte(char **args);

    bool argument_is_index(op_t op);
    int argument_get_type(char const *arg);
    int argument_get_size(char const *arg, op_t op);
    int argument_get_value(char const *arg, instruction_t *instruction,
                                        instruction_t **instructions);

    int16_t swap_int16(int16_t val);
    int32_t swap_int32(int32_t val);
#endif