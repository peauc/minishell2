/*
** prepare_pipe.c for piep in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Apr  5 18:58:15 2016 Poc
** Last update Sat Apr  9 17:04:21 2016 Poc
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "mysh.h"

void		close_fdp(int **fdp)
{
  int		i;

  i = 0;
  while (fdp[i])
    {
      free(fdp[i]);
      i++;
    }
  free(fdp);
}

int		get_first_redirection(char *first, int **fdp)
{
  int		i;
  char		*str;

  if ((i = find_left_redirection(first)))
      return (0);
  str = get_next_word(first + i);
  fdp[0][2] = open(str, O_RDONLY);
  printf("str = %s\npos = %d\nfirst redirect |%s|\n", str, i, first);
  i = 0;
}

int		get_redirections(char **str, int **fdp)
{
  char		*first;
  char		*last;

  if (count_pipes(str) == 0 ||
      ((first = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL) ||
      ((last = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL))
    return (0);
  my_strcpy_target(first, str, '|');
  my_rev_strcpy_target(last, str, '|');
  first = epur_str(first);
  last = epur_str(last);
  get_first_redirection(first, fdp);
  printf("first = |%s|\nlast = |%s|\n", first, last);
  return (0);
}

int             **make_pipe_tab(t_args *args)
{
  int           **fdp;
  int           i;

  i = 0;
  if ((fdp = malloc(sizeof(int *) * (count_pipes(args->args) + 1))) == NULL)
    return (NULL);
  fdp[count_pipes(args->args)] = NULL;
  while (i < count_pipes(args->args))
    {
      printf("args->args %s\n", args->args);
      if ((fdp[i] = malloc(sizeof(int) * 4)) == NULL)
	return (NULL);
      pipe(fdp[i]);
      get_redirections(&args->args, fdp);
      fdp[i][2] = 0;
      fdp[i][3] = 1;
      i++;
    }
  fdp[i] = NULL;
  return (fdp);
}
