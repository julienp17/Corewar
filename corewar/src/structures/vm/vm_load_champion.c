/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Load a champion into the virtual machine
*/

#include "vm.h"
#include "my.h"

static int load_champion(vm_t *vm, int fd, int const champion_nb);

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
    int memchunk_size = 0;
    int load_address = 0;
    champion_t *champion = NULL;

    if (champion_nb < 1 || champion_nb > 4) {
        my_puterr("Champion number not in range 1 to 4.\n");
        return (EXIT_FAILURE);
    }
    champion = &(vm->champions[champion_nb - 1]);
    if (champion_load_header(champion, fd) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    champion->registers[0] = champion_nb;
    memchunk_size = MEM_SIZE / vm->nb_champions;
    if (champion->header.prog_size > memchunk_size) {
        my_puterr("Program size is too big\n");
        return (EXIT_FAILURE);
    }
    load_address = memchunk_size * (champion_nb - 1);
    read(fd, &(vm->mem[load_address]), champion->header.prog_size);
    champion->pc = load_address;
    champion->is_alive = true;
    return (EXIT_SUCCESS);
}