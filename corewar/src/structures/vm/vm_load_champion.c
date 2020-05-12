/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Load a champion into the virtual machine
*/

#include "vm.h"
#include "corewar.h"
#include "my.h"

static int load_champion(vm_t *vm, int fd, int const champion_nb);
static int put_in_mem(vm_t *vm, champion_t *champion, int fd);

int vm_load_champion(vm_t *vm, char const *filepath, int const champion_nb)
{
    int fd = 0;
    int status = 0;

    fd = open(filepath, O_RDONLY);
    if (fd < 0) {
        my_puterr("Couldn't open file");
        return (EXIT_FAILURE);
    }
    status = load_champion(vm, fd, champion_nb);
    if (close(fd) < 0) {
        my_puterr("Couldn't close file");
        status = EXIT_FAILURE;
    }
    return (status);
}

static int load_champion(vm_t *vm, int fd, int const champion_nb)
{
    champion_t *champion = NULL;

    if (champion_nb < 1 || champion_nb > 4) {
        my_puterr("Champion number not in range 1 to 4.\n");
        return (EXIT_FAILURE);
    }
    champion = &(vm->champions[champion_nb - 1]);
    if (champion_load_header(champion, fd) == EXIT_FAILURE) {
        my_puterr("Champion header load fail.\n");
        return (EXIT_FAILURE);
    }
    champion->nb = champion_nb;
    champion->regs[0] = champion_nb;
    if (put_in_mem(vm, champion, fd) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    champion->is_alive = true;
    champion_load_instruction(vm->mem, champion);
    return (EXIT_SUCCESS);
}

static int put_in_mem(vm_t *vm, champion_t *champion, int fd)
{
    int memchunk_size = 0;

    memchunk_size = MEM_SIZE / vm->nb_champions;
    if (champion->pc == 0)
        champion->pc = (memchunk_size * (champion->nb - 1)) % MEM_SIZE;
    if (champion->header.prog_size > memchunk_size) {
        my_puterr("Program size is too big\n");
        return (EXIT_FAILURE);
    }
    if (read(fd, &(vm->mem[champion->pc]), champion->header.prog_size) < 0) {
        my_puterr("Error reading file.\n");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}