/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Load a champion into the virtual machine
*/

#include "vm.h"
#include "corewar.h"
#include "my.h"

static int load_champion(vm_t *vm, champion_t *champion, int fd);
static int put_in_mem(vm_t *vm, champion_t *champion, int fd);

int vm_load_champion(vm_t *vm, champion_t *champion)
{
    int fd = 0;
    int status = 0;

    fd = open(champion->file_path, O_RDONLY);
    if (fd < 0) {
        my_puterr("Couldn't open file.\n");
        return (EXIT_FAILURE);
    }
    status = load_champion(vm, champion, fd);
    if (close(fd) < 0) {
        my_puterr("Couldn't close file.\n");
        status = EXIT_FAILURE;
    }
    return (status);
}

static int load_champion(vm_t *vm, champion_t *champion, int fd)
{
    if (champion_load_header(champion, fd) == EXIT_FAILURE) {
        my_puterr("Champion header load fail.\n");
        return (EXIT_FAILURE);
    }
    champion->proc->regs[0] = champion->nb;
    if (put_in_mem(vm, champion, fd) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    proc_load_instruction(vm->mem, champion->proc);
    return (EXIT_SUCCESS);
}

static int put_in_mem(vm_t *vm, champion_t *champion, int fd)
{
    int memchunk_size = 0;

    memchunk_size = MEM_SIZE / vm->nb_champions;
    if (champion->proc->pc <= 0)
        champion->proc->pc = (memchunk_size * (champion->nb - 1)) % MEM_SIZE;
    if (champion->header.prog_size > memchunk_size) {
        my_puterr("Program size is too big\n");
        return (EXIT_FAILURE);
    }
    if (read(fd, &(vm->mem[champion->proc->pc]), champion->header.prog_size)<0){
        my_puterr("Error reading file.\n");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}