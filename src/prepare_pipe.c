/*
** prepare_pipe.c for piep in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Apr  5 18:58:15 2016 Poc
** Last update Tue Apr  5 19:14:11 2016 Poc
*/

#include <stdlib.h>
#include <stdio.h>
#include "mysh.h"

int             **make_pipe_tab(t_args *args)
{
  int           **fdp;
  int           i;

  i = 0;
  if ((fdp = malloc(sizeof(int *) * (count_pipes(args->args) + 1))) == NULL)
    return (NULL);
  fdp[count_pipes(args->args)] = NULL;
  while (fdp[i])
    {
      if ((fdp[i] = malloc(sizeof(int) * 2)) == NULL)
	return (NULL);

      i++;
    }
  fdp[i] = NULL;
  return (fdp);
}
