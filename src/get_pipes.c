/*
** get_pipes.c for pipes in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Thu Mar 31 18:48:02 2016 Poc
** Last update Sat Apr  9 00:05:33 2016 Poc
*/

#include <stdio.h>
#include <stdlib.h>
#include "mysh.h"

static int	add_to_struct(t_args *args)
{
  char		**tab;
  char		*str;

  if ((str = my_strdup(args->args)) == NULL)
    return (1);
  if ((tab = str_wordtab(args->args, '|')) == NULL)
    return (1);
  if (epur_tab(tab) == NULL)
    return (1);
  args->pipes.command = tab;
  args->args = str;
  return (0);
}

int		get_pipes(t_args *args)
{
  while (args)
    {
      add_to_struct(args);
      args = args->next;
    }
  return (0);
}
