/*
** minishell.c for mi in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Mar 29 18:23:01 2016 Poc
** Last update Wed Mar 30 18:33:01 2016 Poc
*/

#include <unistd.h>
#include "mysh.h"

int		minishell(char **ae)
{
  char		*read;
  t_args	*args;

  while (42)
    {
      write(1, "?> ", 3);
      if (!(read = read_it()))
	return (1);
      args = parsing(read);
    }
  return (0);
}
