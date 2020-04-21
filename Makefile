##
## EPITECH PROJECT, 2019
## Corewar
## File description:
## Makefile
##

CC			=	gcc

MAIN		=	$(addprefix $(SRC_D), $(MAIN_F))
OBJ_M		=	$(MAIN:.c=.o)
MAIN_F		=	main.c

SRC			=	$(addprefix $(SRC_D), $(SRC_F))
OBJ			=	$(SRC:.c=.o)
SRC_D		=	src/
SRC_F		=	

SRC_UT   	=	$(addprefix $(SRC_UT_D), $(SRC_UT_F))
OBJ_UT 	 	=	$(SRC_UT:.c=.o)
SRC_UT_D 	= 	tests/
SRC_UT_F 	=

CFLAGS		=	$(WFLAGS) $(INC)

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
	make -C ./lib/my/ all

tests_run: clean makelib $(OBJ) $(OBJ_UT)
	$(CC) -o $(NAME_UT) $(SRC) $(SRC_UT) $(CFLAGS) $(LDFLAGS_UT)
	./$(NAME_UT)

clean:
	rm -f $(OBJ)
	rm -f *.o
	rm -f *.gc*
	make -C ./lib/my/ clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_UT)
	make -C ./lib/my/ fclean

re: fclean all