/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** get_prog
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "champion_data.h"
#include "instruction.h"
#include "op.h"
#include "my.h"
#include "corewar.h"

static void fill_args_meta(instr_t *instruction, unsigned char coding_byte);
static instr_t *add_instr_list(instr_t *instr, instr_t *new_instr);
static instr_t *get_instruction(int fd);

instr_t *get_prog(int fd)
{
    instr_t *instr = NULL;
    instr_t *new_instr = get_instruction(fd);

    while (new_instr != NULL) {
        instr = add_instr_list(instr, new_instr);
        new_instr = get_instruction(fd);
    }
    // for (instr_t *tmp = instr; tmp; tmp = tmp->next) {
    //     if (tmp != NULL) {
    //         printf("%s\n", tmp->op.mnemonique);
    //         for (int i = 0 ; i < tmp->op.nbr_args ; i++) {
    //             printf("\targ %d = %s%d (%d)\n", i,
    //                 tmp->args[i].type == T_REG ? "r" :
    //                 tmp->args[i].type == T_DIR ? "%" :
    //                 "",
    //                 tmp->args[i].value,
    //                 tmp->args[i].size);
    //         }
    //     }
    // }
    return instr;
}

static instr_t *get_instruction(int fd)
{
    instr_t *instr = NULL;
    ssize_t bytes_read = 0;
    int buf = 0;
    unsigned char coding_byte = 0;

    instr = instruction_create();
    if (instr == NULL)
        return NULL;
    bytes_read = read(fd, &buf, sizeof(char));
    if (bytes_read == 0)
        return NULL;
    instr->op = op_get_by_code(buf);
    if (op_has_coding_byte(instr->op))
        bytes_read = read(fd, &(coding_byte), sizeof(unsigned char));
    else
        coding_byte = 0b10000000;
    fill_args_meta(instr, coding_byte);
    for (int i = 0 ; i < instr->op.nbr_args ; i++) {
        bytes_read = read(fd, &(instr->args[i].value), instr->args[i].size);
        if (instr->args[i].type == T_IND || (instr->args[i].type == T_DIR && argument_is_index(instr->op)))
            instr->args[i].value = (short int)swap_int16(instr->args[i].value);
        else if (instr->args[i].type == T_DIR)
            instr->args[i].value = swap_int32(instr->args[i].value);
    }
    return instr;
}

static void fill_args_meta(instr_t *instr, unsigned char coding_byte)
{
    instr->args[0].type = (coding_byte & 0b11000000) >> 6;
    instr->args[1].type = (coding_byte & 0b00110000) >> 4;
    instr->args[2].type = (coding_byte & 0b00001100) >> 2;
    instr->args[3].type = (coding_byte & 0b00000011);
    for (int i = 0 ; i < instr->op.nbr_args ; i++) {
        instr->args[i].size = argument_get_size(instr->args[i].type, instr->op);
    }
}

static instr_t *add_instr_list(instr_t *instr, instr_t *new_instr)
{
    instr_t *tmp = instr;

    if (instr == NULL)
        return new_instr;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new_instr;
    return instr;
}