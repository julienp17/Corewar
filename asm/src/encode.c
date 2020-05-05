/*
** EPITECH PROJECT, 2020
** Corewar Assembler
** File description:
** Encode instructions to a file
*/

#include "asm.h"
#include "my.h"

label_t **get_labels(char **instructions);
static label_t **allocate_labels(char **instructions);
static int16_t instruction_get_offset(char const *instruction);

int encode_to_file(char const *output_filename, char **instructions)
{
    int fd = 0;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    int status = EXIT_SUCCESS;

    fd = open(output_filename, O_CREAT | O_TRUNC | O_WRONLY, mode);
    if (fd < 0) {
        my_puterr("Error opening file.\n");
        return (EXIT_FAILURE);
    }
    status = encode(fd, instructions);
    if (close(fd) < 0) {
        my_puterr("Error closing file.\n");
        status = EXIT_FAILURE;
    }
    return (status);
}

int encode(int fd, char **instructions)
{
    ssize_t total_bytes_written = 0;
    ssize_t bytes_written = 1;
    label_t **labels = NULL;

    labels = get_labels(instructions);

    if (encode_header(fd, instructions) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    my_strarr_rotate(instructions, 0);
    if (my_str_beg(instructions[0], COMMENT_CMD_STRING))
        my_strarr_rotate(instructions, 0);
    for (uint i = 0 ; bytes_written >= 0 && instructions[i] ; i++) {
        bytes_written = encode_instruction(fd, instructions[i], labels, total_bytes_written);
        total_bytes_written += bytes_written;
    }
    if (bytes_written < 0)
        return (EXIT_FAILURE);
    if (lseek(fd, sizeof(int) * 2 + sizeof(char) * PROG_NAME_LENGTH, SEEK_SET) < 0){
        my_puterr("Coudln't lseek back to program size.\n");
        return (EXIT_FAILURE);
    }
    total_bytes_written = swap_int32(total_bytes_written);
    if (write(fd, &(total_bytes_written), sizeof(int)) < 0) {
        my_puterr("Coudln't write program size.\n");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

label_t **get_labels(char **instructions)
{
    label_t **labels = NULL;
    int16_t offset = 0;
    char **tokens = 0;
    unsigned int label_index = 0;

    labels = allocate_labels(instructions);
    if (labels == NULL)
        return (NULL);
    for (uint i = 2 ; instructions[i] ; i++) {
        tokens = my_str_to_word_array(instructions[i], ' ');
        if (my_str_ends_char(tokens[0], LABEL_CHAR)) {
            tokens[0][my_strlen(tokens[0]) - 1] = '\0';
            labels[label_index++] = label_create(tokens[0], offset);
        }
        offset += instruction_get_offset(instructions[i]);
        my_free_str_array(tokens);
    }
    return (labels);
}

static label_t **allocate_labels(char **instructions)
{
    char **tokens = NULL;
    label_t **labels = NULL;
    unsigned int nb_labels = 0;

    for (uint i = 0 ; instructions[i] ; i++) {
        tokens = my_str_to_word_array(instructions[i], ' ');
        if (my_str_ends_char(tokens[0], LABEL_CHAR))
            nb_labels++;
        my_free_str_array(tokens);
    }
    labels = malloc(sizeof(label_t *) * (nb_labels + 1));
    if (labels == NULL) {
        my_puterr("Couldn't allocate memory for label array.\n");
        return (NULL);
    }
    for (uint i = 0 ; i <= nb_labels ; i++)
        labels[i] = NULL;
    return (labels);
}

static int16_t instruction_get_offset(char const *instruction)
{
    char **tokens = NULL;
    op_t op;
    int16_t offset = 0;
    int arg_size = 0;
    int total_args_size = 0;

    tokens = parse_instruction(instruction);
    if (my_str_ends_char(tokens[0], LABEL_CHAR))
        my_strarr_rotate(tokens, 0);
    if (tokens[0] == NULL)
        return (0);
    op = get_op_by_name(tokens[0]);
    if (op.mnemonique == 0)
        return (-1);
    offset += sizeof(char);
    offset += (should_write_coding_byte(op));
    for (uint i = 1 ; tokens[i] ; i++) {
        arg_size = get_argument_size(op, tokens[i]);
        total_args_size += arg_size;
    }
    offset += total_args_size;
    return (offset);
}