##
## EPITECH PROJECT, 2019
## my_printf
## File description:
## Makefile
##

CC 			= 	gcc

OBJ 		= 	$(SRC:.c=.o) $(SRC_MY_PRINTF:.c=.o)
SRC			= 	$(addprefix $(SRC_D), $(SRC_F))
SRC_F 		=	my_atoi.c \
				my_char_is_alpha_lower.c \
				my_char_is_alpha_upper.c \
				my_char_is_alpha.c \
				my_char_is_alphanum.c \
				my_char_is_digit.c \
				my_clean_str.c \
				my_count_char.c \
				my_count_until_sep.c \
				my_free_str_array.c \
				my_free_str_array.c \
				my_intlen.c \
				my_putchar.c \
				my_puterr.c \
				my_putstr.c \
				my_revstr.c \
				my_str_beg.c \
				my_str_contains_char.c \
				my_str_contains.c \
				my_str_delim.c \
				my_str_ends_char.c \
				my_str_get_index.c \
				my_str_is_alpha.c \
				my_str_is_alphanum.c \
				my_str_is_empty.c \
				my_str_rotate.c \
				my_str_to_lower.c \
				my_str_to_word_array.c \
				my_strarr_len.c \
				my_strarr_remove_empty.c \
				my_strarr_rotate.c \
				my_strcat.c \
				my_strcmp.c \
				my_strcpy.c \
				my_strdup.c \
				my_strdupcat.c \
				my_strlen.c \
				my_strnum_to_uint.c \
				my_strstr.c \

SRC_MY_PRINTF   =	$(addprefix $(SRC_MY_PRINTF_D), $(SRC_MY_PRINTF_F))
SRC_MY_PRINTF_D = 	my_printf/
SRC_MY_PRINTF_F =   my_printf.c \
					my_eprintf.c \
					my_get_converter.c \
					my_get_length_modifier.c \
					my_get_width_field.c \
					my_get_precision.c \
					my_get_flag.c \
					my_get_formatted_output.c \
					booleans/my_is_converter.c \
					booleans/my_is_flag.c \
					booleans/my_is_int_converter.c \
					booleans/my_is_int_signed_converter.c \
					booleans/my_is_int_unsigned_converter.c \
					booleans/my_is_printable.c \
					booleans/my_str_isnum_neg.c \
					booleans/my_str_isnum_pos.c \
					booleans/my_str_isnum.c \
					converters/my_arg_to_str.c \
					converters/my_char_to_octal.c \
					converters/my_char_to_str.c \
					converters/my_decimal_to_binary.c \
					converters/my_decimal_to_hexa_lower.c \
					converters/my_decimal_to_hexa_upper.c \
					converters/my_decimal_to_octal.c \
					converters/my_int_to_strnum.c \
					converters/my_np_to_str.c \
					converters/my_ptr_to_hexa_lower.c \
					converters/my_ptr_to_hexa_upper.c \
					converters/my_uint_to_strnum.c \
					flags/my_hash_flag_convertion.c \
					flags/my_minus_flag_convertion.c \
					flags/my_plus_flag_convertion.c \
					flags/my_space_flag_convertion.c \
					flags/my_zero_flag_convertion.c \
					length_modifiers/my_llint_to_strnum.c \
					length_modifiers/my_lluint_to_strnum.c \
					length_modifiers/my_lluint_to_octal.c \
					length_modifiers/my_lluint_to_hexa_lower.c \
					length_modifiers/my_lluint_to_hexa_upper.c \

INCLUDE		=	-I./

CFLAGS		= 	-W -Wall -Wextra -Werror $(INCLUDE)

DBFLAGS		=	-g -g3 -ggdb

NAME 		= 	libmy.a

HEADER		=	my.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp $(HEADER) ../../include/

clean:
	rm -f *.o $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all
