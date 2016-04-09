/*
** werror.c for werror in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Apr  5 00:53:39 2016 Poc
** Last update Sat Apr  9 03:15:48 2016 Poc
*/

#include <unistd.h>
#include "mysh.h"

void	werror(char *str)
{
  write (2, str, my_strlen(str));
}
