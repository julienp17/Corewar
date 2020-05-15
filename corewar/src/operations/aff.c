/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Execute an 'aff' instruction
*/

#include "vm.h"
#include "my.h"

int aff(vm_t *vm, proc_t *proc)
{
    int reg_nb = 0;
    int value = 0;

    (void)vm;
    reg_nb = proc->instruction->args[0].value;
    value = proc->regs[reg_nb - 1] % 256;
    my_putchar(value);
    return (EXIT_SUCCESS);
}