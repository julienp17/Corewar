##
## EPITECH PROJECT, 2019
## Pushswap
## File description:
## Libmy Makefile
##

CC 		= 	gcc

SRC		=	my_atoi.c \
			my_puterr.c \
			my_str_isnum_pos.c \
			my_strcmp.c \
			my_strcpy.c \
			my_count_char.c \
			my_count_until_sep.c \
			my_str_to_word_array.c \
			my_strdup.c \
			my_free_str_array.c \
			my_strlen.c \
			my_strarr_len.c \
			my_str_contains.c \
			my_int_to_strnum.c \
			my_revstr.c \
			my_int_to_strnum.c \
			my_putstr.c \
			my_putchar.c \
			my_intlen.c \
			my_sqrt.c \
			my_put_nbr.c \
			my_strcat.c \
			my_str_ends.c \
			my_str_is_empty.c \
			my_strdupcat.c \
			my_strarr_remove_empty.c \
			my_strarr_rotate.c \
			my_str_get_index.c \
			my_clean_str.c \
			my_char_is_num.c \
			my_str_delim.c \
			my_strncmp.c \
			my_str_beg.c \
			my_str_rotate.c \
			my_str_ends_char.c \
			my_str_contains_char.c \
			my_strarr_put.c \

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror

DBFLAGS	=	-g -g3 -ggdb

HEADER	=	my.h

NAME	=	libmy.a

all:		$(OBJ)
			ar rc $(NAME) $(OBJ)
			cp $(NAME) ../
			cp $(HEADER) ../../include

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)
			rm -f ../$(NAME)
			rm -f ../../include/$(HEADER)

re:			fclean all

.phony:		re fclean clean
