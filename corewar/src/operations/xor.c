/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** xor
*/

#include "vm.h"
#include "my.h"

int xor(vm_t *vm, proc_t *proc)
{
    int reg_nb = 0;
    int add1 = 0;
    int add2 = 0;

    (void)vm;
    reg_nb = proc->instruction->args[0].value;
    add1 = proc->regs[reg_nb - 1];
    reg_nb = proc->instruction->args[1].value;
    add2 = proc->regs[reg_nb - 1];
    reg_nb = proc->instruction->args[2].value;
    proc->regs[reg_nb - 1] = add1 ^ add2;
    return (proc->regs[reg_nb - 1]);
}