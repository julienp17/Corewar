/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** file_informations
*/

#include "op.h"

#ifndef FILE_INFO_H_
#define FILE_INFO_H_

typedef struct s_files_info {
    header_t header;
    //prog var
}files_inf_t;

typedef struct s_prog_info {
    int prog_name;
    char *file_path;
    int load_address;
    struct s_prog_info *next;
}prog_info_t;

typedef struct s_my_get_opt {
    int nb_cycle;
    prog_info_t *prog;
}my_get_opt_t;

header_t get_header(int fd);
void read_files(prog_info_t *filepaths, int nb_prog);
my_get_opt_t *my_get_opt(char **av);

#endif /* !FILE_INFO_H_ */
