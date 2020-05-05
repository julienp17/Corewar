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

SRC_F		=	fill_buffer.c \
				get_opt/my_get_opt.c \
				get_file_size.c \
				get_files/read_files.c \
				get_files/get_header.c \

SRC_UT   	=	$(addprefix $(SRC_UT_D), $(SRC_UT_F))
OBJ_UT 	 	=	$(SRC_UT:.c=.o)
SRC_UT_D 	= 	tests/
SRC_UT_F 	=

CFLAGS		=	$(WFLAGS) $(INC) $(LDFLAGS)

INC			=	-I./include

WFLAGS		=	-W -Wall -Wextra

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