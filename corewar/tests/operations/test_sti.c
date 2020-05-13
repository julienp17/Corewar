/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Unit tests for 'sti' operation
*/

#include <criterion/criterion.h>
#include "operation.h"

Test(sti, standard_sti_forward)
{
    vm_t *vm = NULL;
    champion_t *champion = NULL;
    int status = 0;
    int address = 0;
    char const expected[sizeof(int)] = {0x00, 0x00, 0x00, 0x01};

    vm = vm_create();
    champion = &(vm->champions[0]);
    champion->regs[0] = 0x00000001;
    champion->instruction->args[0].type  = T_REG;
    champion->instruction->args[0].value = 1;
    champion->instruction->args[1].type  = T_DIR;
    champion->instruction->args[1].value = 7;
    champion->instruction->args[2].type  = T_DIR;
    champion->instruction->args[2].value = 1;
    champion->pc = 0;
    status = sti(vm, champion);
    cr_assert_eq(status, EXIT_SUCCESS);
    for (unsigned long int i = 0 ; i < sizeof(int) ; i++) {
        address = champion->pc + 7 + 1 + i;
        cr_assert_eq(vm->mem[address], expected[i]);
    }
}

Test(sti, standard_sti_forward_more_than_mem)
{
    vm_t *vm = NULL;
    champion_t *champion = NULL;
    int status = 0;
    char const expected[sizeof(int)] = {0x12, 0x34, 0x56, 0x78};

    vm = vm_create();
    champion = &(vm->champions[0]);
    champion->regs[0] = 0x12345678;
    champion->instruction->args[0].type  = T_REG;
    champion->instruction->args[0].value = 1;
    champion->instruction->args[1].type  = T_DIR;
    champion->instruction->args[1].value = 1;
    champion->instruction->args[2].type  = T_DIR;
    champion->instruction->args[2].value = 1;
    champion->pc = MEM_SIZE - 4;
    status = sti(vm, champion);
    cr_assert_eq(status, EXIT_SUCCESS);
    cr_assert_eq(vm->mem[MEM_SIZE - 2], expected[0]);
    cr_assert_eq(vm->mem[MEM_SIZE - 1], expected[1]);
    cr_assert_eq(vm->mem[0], expected[2]);
    cr_assert_eq(vm->mem[1], expected[3]);
}