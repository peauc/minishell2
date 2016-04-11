##
## Makefile for make in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishell1
##
## Made by Clement Peau
## Login   <peau_c@epitech.net>
##
## Started on  Thu Jan  7 16:17:02 2016 Clement Peau
## Last update Mon Apr 11 22:37:40 2016 Poc
##

DEBUG=	yes

SRC=	arlen.c			\
	builtin.c		\
	calc.c			\
	cd.c			\
	copy_env.c		\
	count_in_wordtab.c	\
	cut_line.c		\
	core.c			\
	epur.c			\
	environ_parsing.c	\
	env.c			\
	execute_pipes.c		\
	exit.c			\
	free_all.c		\
	find_redirection.c	\
	get_pipes.c		\
	get_next_word.c		\
	last_redirection.c	\
	linked_list.c		\
	main.c 			\
	make_new_env_var.c	\
	minishell.c		\
	my_getnbr.c		\
	my_strcat.c		\
	my_strcpy.c		\
	my_strcnc.c		\
	my_strcmp.c		\
	my_strncmp.c		\
	my_strlen.c		\
	my_strdup.c		\
	parsing.c		\
	path_managing.c		\
	prepare_pipe.c		\
	read.c			\
	unsetenv.c		\
	showtab.c		\
	simple_exec.c		\
	setenv.c		\
	validate_string.c	\
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
	@echo " ____________________ ________________________   ____ ___._________________";
	@echo "/   _____/\_   _____|/  _____/\_   _____/  _  \ |    |   \    | \__    ___/";
	@echo "\_____  \  |    ___|/   \  ___ |    __)/  / \  \|    |   /    |   |    |";
	@echo "/        \ |        \    \_\  \|     \/    |    \    |  /|    |___|    |";
	@echo "/________//_________/\________/\_____/\____|____/______/ |________|____|";
	@tput sgr0
	rm -rf TAGS
	find . -type f -iname "*.[chS]" | xargs etags -a
endif
	@ echo "CC = $(CC)"
	@ echo "CFLAGS = $(CFLAGS)"
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
