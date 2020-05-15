/*
** EPITECH PROJECT, 2020
** Corewar proc
** File description:
** Returns a newly allocated processus structure
*/

#include <stdlib.h>
#include "champion.h"
#include "my.h"

proc_t *proc_create(int pc)
{
    proc_t *proc = NULL;

    proc = malloc(sizeof(proc_t));
    if (proc == NULL) {
        my_puterr("Couldn't allocate memory for proc structure.\n");
        return (NULL);
    }
    proc->pc = pc;
    proc->carry = false;
    proc->cycle_wait = 0;
    proc->instruction = instruction_create();
    for (int i = 0 ; i < REG_NUMBER ; i++)
        proc->regs[i] = 0;
    proc->next = NULL;
    return (proc);
}