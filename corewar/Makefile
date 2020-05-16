##
## EPITECH PROJECT, 2019
## Corewar
## File description:
## Virtual machine Makefile
##

CC			=	gcc

MAIN		=	$(addprefix $(SRC_D), $(MAIN_F))
OBJ_M		=	$(MAIN:.c=.o)
MAIN_F		=	main.c

SRC			=	$(addprefix $(SRC_D), $(SRC_F))
OBJ			=	$(SRC:.c=.o)
SRC_D		=	src/

SRC_F		=	op.c \
				corewar.c \
				arguments/argument_is_index.c \
				arguments/argument_get_size.c \
				arguments/arguments_are_correct.c \
				arguments/argument_get_value.c \
				get_opt/my_get_opt.c \
				get_opt/free_list.c \
				get_opt/add_info.c 	\
				get_opt/prog_nb.c 	\
				get_opt/error_opt.c \
				get_opt/fill_champion.c \
				operations/operation_get.c \
				operations/live.c \
				operations/ld.c \
				operations/st.c \
				operations/add.c \
				operations/sub.c \
				operations/and.c \
				operations/or.c \
				operations/xor.c \
				operations/zjmp.c \
				operations/sti.c \
				operations/fork.c \
				operations/lld.c \
				operations/lfork.c \
				operations/aff.c \
				structures/champion/champion_load_header.c \
				structures/champion/champion_execute.c \
				structures/proc/proc_create.c \
				structures/proc/proc_load_instruction.c \
				structures/instruction/instruction_create.c \
				structures/instruction/instruction_reset.c \
				structures/vm/vm_create.c \
				structures/vm/vm_destroy.c \
				structures/vm/vm_load_champion.c \
				structures/vm/vm_should_continue.c \
				structures/vm/vm_dump.c \
				utilities/swap_endianess.c \
				utilities/get_index.c \
				utilities/mem_manipulation.c \

SRC_UT   	=	$(addprefix $(SRC_UT_D), $(SRC_UT_F))
OBJ_UT 	 	=	$(SRC_UT:.c=.o)
SRC_UT_D 	= 	tests/
SRC_UT_F 	=	test_op_is_null.c \
				test_op_get_by_code.c \
				test_get_index.c \
				arguments/test_argument_get_size.c \
				arguments/test_argument_is_index.c \
				operations/test_st.c \
				operations/test_add.c \
				operations/test_sub.c \
				operations/test_zjmp.c \
				operations/test_and.c \
				operations/test_or.c \
				operations/test_xor.c \
				test_champion_load_header.c \
				#operations/test_ld.c \

CFLAGS		=	$(WFLAGS) $(INC) $(LDFLAGS)

INC			=	-I./include

WFLAGS		=	-W -Wall -Wextra -Werror

LDFLAGS		=	-L./lib -lmy

LDFLAGS_UT	= 	-lcriterion -lgcov --coverage

DBFLAGS		=	-g -g3 -ggdb

NAME 		=	corewar

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