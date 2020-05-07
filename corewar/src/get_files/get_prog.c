/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** get_prog
*/

#include "file_informations.h"
#include <unistd.h>
#include "instructions.h"
#include "op.h"

op_t op_get_by_code(unsigned char code);
static params_t **get_params_type(params_t **params, char buf, op_t op);

void get_prog(int fd)
{
    instr_t *instr = NULL;
    params_t **params = NULL;
    op_t op;
    int read_size = sizeof(char);
    int curr_rd = R_INST;
    char buf[read_size];

    read(fd, &buf, HEADER_SIZE);
    for (int status = 0; status > 0; status = read(fd, &buf, read_size)) {
        if (curr_rd == R_INST)
            op = op_get_by_code(*buf);
        if (curr_rd == R_CODE)
            params = get_params_type(params, *buf, op);
    }
}

static params_t **get_params_type(params_t **params, char coding_byte, op_t op)
{
    params = malloc(sizeof(params_t *) * op.nbr_args + 1);
    params[op.nbr_args] = NULL;
    int mask = 0b11000000;

    for (int i = 0; params[i]; i++) {
        
    }
}