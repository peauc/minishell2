/*
** prepare_pipe.c for piep in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Apr  5 18:58:15 2016 Poc
** Last update Wed Apr  6 02:28:10 2016 Poc
*/

#include <stdlib.h>
#include <stdio.h>
#include "mysh.h"

int		close_fpd(int **fdp)
{
  int		i;

  i = 0;
  while (fdp[i])
    {
      close(fdp[0][0]);
      close(fdp[0][1]);
      i++;
    }
}

int             **make_pipe_tab(t_args *args)
{
  int           **fdp;
  int           i;

  i = 0;
  printf("NB OF PIPE %d\n", count_pipes(args->args));
  if ((fdp = malloc(sizeof(int *) * (count_pipes(args->args) + 1))) == NULL)
    return (NULL);
  fdp[count_pipes(args->args)] = NULL;
  while (i < count_pipes(args->args))
    {
      printf("hello\n");
      if ((fdp[i] = malloc(sizeof(int) * 2)) == NULL)
	return (NULL);
      pipe(fdp[i]);
      i++;
    }
  fdp[i] = NULL;
  return (fdp);
}
