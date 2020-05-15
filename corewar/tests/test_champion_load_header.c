/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** test_champion_load_header
*/

#include <fcntl.h>
#include <criterion/criterion.h>
#include "champion.h"

Test(champion_load_header, load_header_good_magic)
{
    int fd = 0;
    int status = 42;
    int expected = 0;
    champion_t champ = (champion_t) {
        (header_t) {0, {0}, 0, {0}}, NULL, 0, 0, 0, NULL
    };

    if ((fd = open("references/abel.cor", O_RDONLY) < 0))
        return;
    champ.header.magic = COREWAR_EXEC_MAGIC;
    status = champion_load_header(&champ, fd);
    cr_assert_eq(status, expected);
}

Test(champion_load_header, load_header_wrong_magic)
{
    int fd = 0;
    int status = 42;
    int expected = 1;
    champion_t champ = (champion_t) {
        (header_t) {0, {0}, 0, {0}}, NULL, 0, 0, 0, NULL
    };

    if ((fd = open("references/abel.cor", O_RDONLY) < 0))
        return;
    champ.header.magic = 84;
    status = champion_load_header(&champ, fd);
    cr_assert_eq(status, expected);
}

Test(champion_load_header, load_header_wrong_fd)
{
    int fd = -1;
    int status = 42;
    int expected = 1;
    champion_t champ = (champion_t) {
        (header_t) {0, {0}, 0, {0}}, NULL, 0, 0, 0, NULL
    };

    champ.header.magic = 84;
    status = champion_load_header(&champ, fd);
    cr_assert_eq(status, expected);
}