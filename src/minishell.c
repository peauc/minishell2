/*
** minishell.c for mi in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Mar 29 18:23:01 2016 Poc
** Last update Sat Apr  2 18:25:22 2016 Poc
*/

#include <stdlib.h>
#include <unistd.h>
#include "mysh.h"

int		minishell(char **ae)
{
  char		*read;
  t_args	*args;

  args = NULL;
  while (42)
    {
      write(1, "?> ", 3);
      if (!(read = read_it()))
	{
	  free_all(ae, read);
	  return (1);
	}
      if (read[0] != 0)
	{
	  args = parsing(read);
	  get_pipes(args);
	  core(args, ae);
	  free_tab(args->pipes.command);
	  free_args(args);
	}
      else
	free(read);
    }
  return (0);
}
