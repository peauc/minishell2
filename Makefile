##
## Makefile for make in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishell1
##
## Made by Clement Peau
## Login   <peau_c@epitech.net>
##
## Started on  Thu Jan  7 16:17:02 2016 Clement Peau
## Last update Thu Apr  7 10:11:06 2016 Poc
##

DEBUG=	no

SRC=	arlen.c			\
	calc.c			\
	copy_env.c		\
	count_in_wordtab.c	\
	cut_line.c		\
	core.c			\
	epur.c			\
	execute_pipes.c		\
	free_all.c		\
	get_pipes.c		\
	linked_list.c		\
	main.c 			\
	minishell.c		\
	my_strcat.c		\
	my_strcpy.c		\
	my_strncmp.c		\
	my_strlen.c		\
	my_strdup.c		\
	parsing.c		\
	path_managing.c		\
	prepare_pipe.c		\
	read.c			\
	showtab.c		\
	simple_exec.c		\
	werror.c		\
	wordtab.c		\

OBJ=	$(addprefix src/, $(SRC:.c=.o))

RM=	rm -f

ifeq ($(DEBUG), yes)
	CFLAGS=		$(HEAD) -W -Wall -Wextra -ansi -pedantic -g -D DEBUG
	CC=		clang
else
	CFLAGS=		$(HEAD) -W -Wall -Wextra -ansi -pedantic
	CC=		gcc
endif

NAME=	mysh

HEAD=	-I inc/

$(NAME):                $(OBJ)
ifeq ($(DEBUG), yes)
	@tput setaf 1; tput bold
	@echo "____________________ ________________________   ____ ___._________________";
	@echo "/   _____/\_   _____|/  _____/\_   _____/  _  \ |    |   \    | \__    ___/";
	@echo "\_____  \  |    ___|/   \  ___ |    __)/  / \  \|    |   /    |   |    |";
	@echo "/        \ |        \    \_\  \|     \/    |    \    |  /|    |___|    |";
	@echo "/________//_________/\________/\_____/\____|____/______/ |________|____|";
	@tput sgr0
	find . -type f -iname "*.[chS]" | xargs etags -a
endif
	@ $(CC) $(OBJ) -o $(NAME)
	@ echo -e "\033[1;31m \t \t \n \t ♩♪♫ $(NAME) Compiled\033[0;31m®\033[1;31m Created Sucesfully \033[0m"

all:		$(NAME)

clean:
		@ $(RM) $(OBJ)
		@ echo "[ OK ] clean sucessfull"
fclean: clean
		@ $(RM) $(NAME)
		@ echo "[ OK ] fclean succesfull"

re:	fclean all
%.o:                    %.c
			@ echo "[ OK ] Compiling" $<
			@ $(CC) -o $@ -c $< $(CFLAGS)
test:
			gcc -o test src/execute_pipes.c test.c -I./inc
