/*
** prepare_pipe.c for piep in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Apr  5 18:58:15 2016 Poc
** Last update Mon Apr 11 22:39:59 2016 Poc
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
    return (werror("Cannot open : "), werror(str), werror("\n"), 1);
  *first = erase_redirection(*first);
  i = 0;
  printf("Get_first %s\n", *first);
  return (0);
}

int		get_redirections(char ***str, int **fdp, int i, int max)
{
  if (fdp[0])
    {
      fdp[0][2] = 0;
      fdp[0][3] = 1;
      fdp[0][4] = 0;
      fdp[0][5] = 1;
      if ((get_first_redirection(str[0], fdp)) ||
	  (get_last_redirection(&((*str)[arlen(*str) - 1]), fdp[0])))
	return (1);
    }
  return (0);
}

int             **make_pipe_tab(char **pipes)
{
  int           **fdp;
  int           i;

  i = 0;
  if (arlen(pipes) == 0 ||
      (fdp = malloc(sizeof(int *) * (arlen(pipes)))) == NULL)
    return (NULL);
  while (i < arlen(pipes) - 1)
    {
      if ((fdp[i] = malloc(sizeof(int) * 2)) == NULL)
	return (NULL);
      if (i == 0)
	{
	  free(fdp[0]);
	  if ((fdp[0] = malloc(sizeof(int) * 6)) == NULL)
	    return (NULL);
	}
      pipe(fdp[i]);
      i++;
    }
  fdp[(arlen(pipes) == 0 ? 0 : arlen(pipes) - 1)] = NULL;
  if ((get_redirections(&pipes , fdp, i, arlen(pipes) - 1)))
      return (NULL);
  return (fdp);
}
