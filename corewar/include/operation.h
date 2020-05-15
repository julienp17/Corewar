/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Operations
*/

#ifndef OPERATIONS_H_
    #define OPERATIONS_H_

    #include "vm.h"

    typedef struct operation {
        int code;
        int (*function)(vm_t *, proc_t *proc);
    } operation_t;

    int (*operation_get(int const code))(vm_t *, proc_t *);
    int live(vm_t *vm, proc_t *proc);
    int ld(vm_t *vm, proc_t *proc);
    int st(vm_t *vm, proc_t *proc);
    int add(vm_t *vm, proc_t *proc);
    int sub(vm_t *vm, proc_t *proc);
    int and(vm_t *vm, proc_t *proc);
    int or(vm_t *vm, proc_t *proc);
    int xor(vm_t *vm, proc_t *proc);
    int zjmp(vm_t *vm, proc_t *proc);
    int sti(vm_t *vm, proc_t *proc);
    int proc_fork(vm_t *vm, proc_t *proc);
    int lld(vm_t *vm, proc_t *proc);
    int lldi(vm_t *vm, proc_t *proc);
    int proc_lfork(vm_t *vm, proc_t *proc);
    int aff(vm_t *vm, proc_t *proc);
#endif