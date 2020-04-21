##
## EPITECH PROJECT, 2019
## Corewar
## File description:
## Root Makefile
##

all:
	make -C ./asm/ all
	make -C ./corewar/ all

tests_run: clean
	make -C ./asm/ tests_run
	make -C ./corewar/ tests_run

clean:
	make -C ./asm/ clean
	make -C ./corewar/ clean

fclean: clean
	make -C ./asm/ fclean
	make -C ./corewar/ fclean

re: fclean all