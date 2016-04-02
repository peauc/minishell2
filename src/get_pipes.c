/*
** get_pipes.c for pipes in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Thu Mar 31 18:48:02 2016 Poc
** Last update Sat Apr  2 18:08:04 2016 Poc
*/

#include <stdio.h>
#include <stdlib.h>
#include "mysh.h"

static int	add_to_struct(t_args *args)
{
  int		i;
  char		**tab;
  char		*str;

  i = 0;
  if ((str = my_strdup(args->args)) == NULL)
    return (1);
  if ((tab = str_wordtab(args->args, '|')) == NULL)
    return (1);
  printf("tab\n");
  if (epur_tab(tab) == NULL)
    return (1);
  args->pipes.command = tab;
  showtab(args->pipes.command);
  args->args = str;
  return (0);
}

int		get_pipes(t_args *args)
{
  while (args)
    {
      printf("count pipes%d\n", count_pipes(args->args));
      printf("%s\n", args->args);
      add_to_struct(args);
      args = args->next;
    }
  return (0);
}
