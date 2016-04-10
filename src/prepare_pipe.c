/*
** prepare_pipe.c for piep in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Apr  5 18:58:15 2016 Poc
** Last update Sun Apr 10 13:29:45 2016 Poc
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

char		*erase_redirection(char *str)
{
  int		i;
  int		space;
  char		*tmp;

  space = 0;
  i = 0;
  if (str[0] == '<')
    {
      while (str[i] && space < 2)
      {
	if (str[i] == ' ')
	  space++;
	i++;
      }
      tmp = my_strdup(str + i);
      return (free(str), tmp);
    }
  else
    {
      tmp = my_strdup(str);
      while (tmp && tmp[i] != ' ')
	i++;
      tmp[i] = 0;
      return (free(str), tmp);
    }
}

int		get_first_redirection(char **first, int **fdp)
{
  int		i;
  char		*str;

  if ((i = find_left_redirection(*first)) == -1)
      return (0);
  str = get_next_word(*first + i);
  if ((fdp[0][2] = open(str, O_RDONLY)) == -1)
    return (werror("Cannot open :"), werror(str), 1);
  *first = erase_redirection(*first);
  i = 0;
}

int		get_redirections(char **str, int **fdp, int i)
{
  if (i == 0)
    get_first_redirection(str, fdp);
  return (0);
}

int             **make_pipe_tab(char **pipes)
{
  int           **fdp;
  int           i;

  i = 0;
  if ((fdp = malloc(sizeof(int *) * (arlen(pipes) + 1))) == NULL)
    return (NULL);
  fdp[arlen(pipes)] = NULL;
 while (pipes[i + 1])
    {
      if ((fdp[i] = malloc(sizeof(int) * 4)) == NULL)
	return (NULL);
      pipe(fdp[i]);
      fdp[i][2] = 0;
      fdp[i][3] = 1;
      get_redirections(&pipes[i] , fdp, i);
      i++;
    }
  fdp[i] = NULL;
  return (fdp);
}
