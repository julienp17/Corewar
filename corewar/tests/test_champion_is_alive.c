/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Unit tests for champion_is_alive
*/

#include <criterion/criterion.h>
#include "champion.h"

Test(champion_is_alive, first_cycle)
{
    int cycle = 0;
    champion_t champion = (champion_t) {
        (header_t) {0, {0}, 0, {0}}, NULL, 0, 0, 0, NULL
    };
    bool actual = false;
    bool expected = true;

    champion.last_live = 0;
    actual = champion_is_alive(&champion, cycle);
    cr_assert_eq(actual, expected);
}

Test(champion_is_alive, cycle_to_die_minus_1)
{
    int cycle = CYCLE_TO_DIE - 1;
    champion_t champion = (champion_t) {
        (header_t) {0, {0}, 0, {0}}, NULL, 0, 0, 0, NULL
    };
    bool actual = false;
    bool expected = true;

    champion.last_live = 0;
    actual = champion_is_alive(&champion, cycle);
    cr_assert_eq(actual, expected);
}

Test(champion_is_alive, cycle_to_die)
{
    int cycle = CYCLE_TO_DIE;
    champion_t champion = (champion_t) {
        (header_t) {0, {0}, 0, {0}}, NULL, 0, 0, 0, NULL
    };
    bool actual = false;
    bool expected = false;

    champion.last_live = 0;
    actual = champion_is_alive(&champion, cycle);
    cr_assert_eq(actual, expected);
}

Test(champion_is_alive, living_with_a_last_live)
{
    int cycle = CYCLE_TO_DIE * 3;
    champion_t champion = (champion_t) {
        (header_t) {0, {0}, 0, {0}}, NULL, 0, 0, 0, NULL
    };
    bool actual = false;
    bool expected = true;

    champion.last_live = CYCLE_TO_DIE * 2 + 52;
    actual = champion_is_alive(&champion, cycle);
    cr_assert_eq(actual, expected);
}

Test(champion_is_alive, not_living_with_a_last_live)
{
    int cycle = CYCLE_TO_DIE * 4;
    champion_t champion = (champion_t) {
        (header_t) {0, {0}, 0, {0}}, NULL, 0, 0, 0, NULL
    };
    bool actual = false;
    bool expected = false;

    champion.last_live = CYCLE_TO_DIE * 2 + 52;
    actual = champion_is_alive(&champion, cycle);
    cr_assert_eq(actual, expected);
}