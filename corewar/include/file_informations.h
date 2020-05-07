/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** file_informations
*/

#include "op.h"

#ifndef FILE_INFO_H_
#define FILE_INFO_H_

enum error_arg {
    INVALID_OPTION = -1,
    INVALID_NB_CHAMP = -2,
    NO_CAMP_SPECI = -3
};

enum data_type {
    PROG_NB,
    LOAD_ADDRESS,
    PROG_NAME
};
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

typedef struct s_get_opt {
    int nb_cycle;
    prog_info_t *prog;
}get_opt_t;

header_t get_header(int fd);
void read_files(prog_info_t *filepaths, int nb_prog);
get_opt_t *my_get_opt(char **av);
prog_info_t *free_list(prog_info_t *list);
int add_prog_infos(char **av, int i , get_opt_t *opt);
int elem_add_n(prog_info_t *add, char **av, int i);
int elem_add_a(prog_info_t *add, char **av, int i, get_opt_t *tmp);
int elem_add_std(prog_info_t *add, char **av, int i, get_opt_t *opt);
int get_prog_nb(get_opt_t *my_prog);
#endif /* !FILE_INFO_H_ */
