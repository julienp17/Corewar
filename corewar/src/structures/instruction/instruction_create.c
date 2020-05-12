/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Returns a newly allocated instruction structure
*/

#include <stdlib.h>
#include "instruction.h"
#include "my.h"

instruction_t *instruction_create(void)
{
    instruction_t *instruction = NULL;

    instruction = malloc(sizeof(instruction_t));
    if (instruction == NULL) {
        my_puterr("Couldn't allocate memory for instruction structure.\n");
        return (NULL);
    }
    instruction->op = (op_t) {0, 0, {0}, 0, 0, 0};
    for (int i = 0 ; i < MAX_ARGS_NUMBER ; i++) {
        instruction->args[i].type = 0;
        instruction->args[i].size = 0;
        instruction->args[i].value = 0;
    }
    return (instruction);
}