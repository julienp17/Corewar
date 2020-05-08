##
## EPITECH PROJECT, 2019
## Corewar
## File description:
## Assembler Makefile
##

CC			=	gcc

MAIN		=	$(addprefix $(SRC_D), $(MAIN_F))
OBJ_M		=	$(MAIN:.c=.o)
MAIN_F		=	main.c

SRC			=	$(addprefix $(SRC_D), $(SRC_F))
OBJ			=	$(SRC:.c=.o)
SRC_D		=	src/
SRC_F		=	assemble.c \
				op.c \
				swap_endianess.c \
				arguments/argument_is_index.c \
				arguments/argument_get_size.c \
				arguments/argument_get_type.c \
				arguments/argument_get_value.c \
				file_control/get_file_buffer.c \
				file_control/get_file_lines.c \
				file_control/get_file_size.c \
				file_control/get_pretty_filename.c \
				instruction/parse_instruction.c \
				instruction/instruction_get_size.c \
				instruction/instruction_get_coding_byte.c \
				instruction/instruction_is_correct.c \
				structures/asm/asm_create.c \
				structures/asm/asm_destroy.c \
				structures/asm/asm_has_an_instruction.c \
				structures/asm/asm_fill.c \
				structures/asm/asm_fill_instruction_value.c \
				structures/asm/asm_fill_instructions_meta.c \
				structures/asm/asm_fill_program_name.c \
				structures/asm/asm_fill_comment.c \
				structures/asm/asm_encode.c \
				structures/asm/asm_encode_header.c \
				structures/asm/asm_puterr.c \
				structures/instruction/instruction_create.c \
				structures/instruction/instruction_destroy.c \
				structures/instruction/instruction_write.c \
				structures/instruction/instruction_is_label.c \

SRC_UT   	=	$(addprefix $(SRC_UT_D), $(SRC_UT_F))
OBJ_UT 	 	=	$(SRC_UT:.c=.o)
SRC_UT_D 	= 	tests/
SRC_UT_F 	=	test_parse_instruction.c \
				test_instruction_is_correct.c \
				test_swap_endianess.c \
				arguments/test_argument_get_size.c \
				structures/asm/test_asm_create.c \

CFLAGS		=	$(WFLAGS) $(INC) $(LDFLAGS)

WFLAGS		=	-W -Wall -Wextra -Werror

INC			=	-I./include

LDFLAGS		=	-L./lib -lmy

LDFLAGS_UT	= 	-lcriterion -lgcov --coverage

DBFLAGS		=	-g -g3 -ggdb

NAME 		=	asm

NAME_UT		=	unit_tests

all:	$(NAME)

$(NAME):	makelib $(OBJ) $(OBJ_M)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_M) $(CFLAGS)

makelib:
	make -C ./lib/my all

tests_run: clean makelib $(OBJ) $(OBJ_UT)
	$(CC) -o $(NAME_UT) $(SRC) $(SRC_UT) $(CFLAGS) $(LDFLAGS_UT)
	./$(NAME_UT)

clean:
	rm -f $(OBJ)
	rm -f *.o
	rm -f *.gc*
	make -C ./lib/my clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_UT)
	make -C ./lib/my fclean

re: fclean all