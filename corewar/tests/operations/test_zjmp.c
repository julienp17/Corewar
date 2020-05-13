/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Test zjmp
*/

#include <criterion/criterion.h>
#include "vm.h"
#include "operation.h"

Test(zjmp, standard_zjmp_back_with_carry)
{
    champion_t champion = (champion_t) {
        (header_t) {0, {0}, 0, {0}}, false, 0, 0, 0, {0}, 0, NULL, false
    };
    int status = 0;

    champion.instruction = instruction_create();
    champion.carry = true;
    champion.instruction->args[0].value = -12;
    champion.instruction->size = 3;
    champion.pc = 19;
    status = zjmp(NULL, &champion);
    cr_assert_eq(status, EXIT_SUCCESS);
    cr_assert_eq(champion.pc, (19 + -12));
    cr_assert_eq(champion.instruction->size, 0);
}

Test(zjmp, standard_zjmp_forward_with_carry)
{
    champion_t champion = (champion_t) {
        (header_t) {0, {0}, 0, {0}}, false, 0, 0, 0, {0}, 0, NULL, false
    };
    int status = 0;

    champion.instruction = instruction_create();
    champion.carry = true;
    champion.instruction->args[0].value = 13;
    champion.instruction->size = 3;
    champion.pc = 10;
    status = zjmp(NULL, &champion);
    cr_assert_eq(status, EXIT_SUCCESS);
    cr_assert_eq(champion.pc, (10 + 13));
    cr_assert_eq(champion.instruction->size, 0);
}

Test(zjmp, standard_zjmp_zero_with_carry)
{
    champion_t champion = (champion_t) {
        (header_t) {0, {0}, 0, {0}}, false, 0, 0, 0, {0}, 0, NULL, false
    };
    int status = 0;

    champion.instruction = instruction_create();
    champion.carry = true;
    champion.instruction->args[0].value = 0;
    champion.instruction->size = 3;
    champion.pc = 10;
    status = zjmp(NULL, &champion);
    cr_assert_eq(status, EXIT_SUCCESS);
    cr_assert_eq(champion.pc, (10 + 0));
    cr_assert_eq(champion.instruction->size, 0);
}

Test(zjmp, zjmp_back_less_than_mem_with_carry)
{
    champion_t champion = (champion_t) {
        (header_t) {0, {0}, 0, {0}}, false, 0, 0, 0, {0}, 0, NULL, false
    };
    int status = 0;

    champion.instruction = instruction_create();
    champion.carry = true;
    champion.instruction->args[0].value = -6;
    champion.instruction->size = 3;
    champion.pc = 3;
    status = zjmp(NULL, &champion);
    cr_assert_eq(status, EXIT_SUCCESS);
    cr_assert_eq(champion.pc, (MEM_SIZE - 3));
    cr_assert_eq(champion.instruction->size, 0);
}

Test(zjmp, zjmp_forward_more_than_mem_with_carry)
{
    champion_t champion = (champion_t) {
        (header_t) {0, {0}, 0, {0}}, false, 0, 0, 0, {0}, 0, NULL, false
    };
    int status = 0;

    champion.instruction = instruction_create();
    champion.carry = true;
    champion.instruction->args[0].value = 4;
    champion.instruction->size = 3;
    champion.pc = MEM_SIZE - 2;
    status = zjmp(NULL, &champion);
    cr_assert_eq(status, EXIT_SUCCESS);
    cr_assert_eq(champion.pc, (2));
    cr_assert_eq(champion.instruction->size, 0);
}

Test(zjmp, zjmp_no_carry)
{
    champion_t champion = (champion_t) {
        (header_t) {0, {0}, 0, {0}}, false, 0, 0, 0, {0}, 0, NULL, false
    };
    int status = 0;

    champion.instruction = instruction_create();
    champion.carry = false;
    champion.instruction->args[0].value = -6;
    champion.instruction->size = 3;
    champion.pc = 3;
    status = zjmp(NULL, &champion);
    cr_assert_eq(status, EXIT_FAILURE);
    cr_assert_eq(champion.pc, champion.pc);
    cr_assert_eq(champion.instruction->size, champion.instruction->size);
}