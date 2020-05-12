/*
** EPITECH PROJECT, 2020
** Corewar VM
** File description:
** Corewar VM header file
*/

#ifndef COREWAR_H_
    #define COREWAR_H_

    #include <stdint.h>
    #include "op.h"
    #include "champion_data.h"
    #include "vm.h"

    int16_t swap_int16(int16_t val);
    int32_t swap_int32(int32_t val);
    op_t op_get_by_code(unsigned char code);
    bool op_has_coding_byte(op_t op);

    int corewar(vm_t *vm, champion_data_t *filepaths);
#endif