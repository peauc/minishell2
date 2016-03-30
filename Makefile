##
## Makefile for make in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishell1
##
## Made by Clement Peau
## Login   <peau_c@epitech.net>
##
## Started on  Thu Jan  7 16:17:02 2016 Clement Peau
## Last update Wed Mar 30 18:52:10 2016 Poc
##

DEBUG=	yes

SRC=	arlen.c			\
	copy_env.c		\
	epur.c			\
	main.c 			\
	linked_list.c		\
	minishell.c		\
	my_strcpy.c		\
	my_strlen.c		\
	my_strdup.c		\
	parsing.c		\
	read.c			\
	showtab.c		\
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
