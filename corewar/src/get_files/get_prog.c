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
#include "instructions.h"
#include "op.h"
#include "my.h"
#include "corewar.h"

static void fill_args_meta(instr_t *instruction);
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
    for (instr_t *tmp = instr; tmp; tmp = tmp->next) {
        if (tmp != NULL) {
            printf("%s  ", tmp->op.mnemonique);
            printf("%x    \n", tmp->coding_byte);
        } //ça segfault ici parce que des fois op.mnemonique = NULL
    }
    return instr;
}

static instr_t *get_instruction(int fd)
{
    instr_t *instr = malloc(sizeof(instr_t));
    ssize_t bytes_read = 0;
    int buf = 0;

    bytes_read = read(fd, &buf, sizeof(char));
    if (bytes_read == 0)
        return NULL;
    instr->op = op_get_by_code(buf);
    if (op_has_coding_byte(instr->op))
        bytes_read = read(fd, &(instr->coding_byte), sizeof(char));
    else
        instr->coding_byte = 0;
    fill_args_meta(instr);
    for (int i = 0 ; i < instr->op.nbr_args ; i++)
        bytes_read = read(fd, &(instr->args[i].value), instr->args[i].size);
    instr->next = NULL;
    return instr;
}

static void fill_args_meta(instr_t *instr)
{
    instr->args[0].type = (instr->coding_byte & 0b11000000) >> 6;
    instr->args[1].type = (instr->coding_byte & 0b00110000) >> 4;
    instr->args[2].type = (instr->coding_byte & 0b00001100) >> 2;
    instr->args[3].type = instr->coding_byte & 0b00000011;
    for (int i = 0 ; i < instr->op.nbr_args ; i++) {
        if (instr->args[i].type == T_REG)
            instr->args[i].size = 1;
        if (instr->args[i].type == (T_IND - 1))
            instr->args[i].size = IND_SIZE;
        if (instr->args[i].type == T_DIR) {
            if (argument_is_index(instr->op))
                instr->args[i].size = IND_SIZE;
            else
                instr->args[i].size = DIR_SIZE;
        }
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