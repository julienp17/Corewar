/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Header file for processus structure
*/

#ifndef PROC_H_
    #define PROC_H_

    #include "instruction.h"

    typedef struct process {
        int pc;
        int cycle_wait;
        int regs[REG_NUMBER];
        instruction_t *instruction;
        bool carry;
        struct process *next;
    } proc_t;

    proc_t *proc_create(int pc);

    int proc_load_instruction(char mem[MEM_SIZE], proc_t *proc);
#endif