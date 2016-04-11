/*
** last_redirection.c for last in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Sun Apr 10 13:53:28 2016 Poc
** Last update Tue Apr 12 01:49:52 2016 Poc
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "mysh.h"

char	*remove_right_redit(char *str)
{
  int           i;
  int           space;
  char          *tmp;

  space = 0;
  i = 0;
  if (str[0] == '>')
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
      while (tmp[i] && tmp[i] != ' ' && tmp[i] != '>')
	i++;
      tmp[i] = 0;
      return (free(str), tmp);
    }
}

int	find_right_redirection(char *str, int *status)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '<')
	return ((*status = -1), werror("Ambiguous outpur redirect\n"), -1);
      if (str[i] == '>')
	{
	  if (str[i + 1] == '>')
	    {
	      *status = 2;
	      return (i);
	    }
	  *status = 1;
	  return (i);
	}
      i++;
    }
  status = 0;
  return (-2);
}

int	get_last_redirection(char **last, int *fdp)
{
  char	*word;
  int	status;
  int	ret;

  status = 0;
  fdp[4] = 0;
  fdp[5] = 1;
  if ((ret = find_right_redirection(*last, &status)) == -1)
    return (1);
  if (ret == -2)
    return (0);
  if ((*last = remove_right_redit(*last)) == NULL ||
      (word = get_next_word(*last + ret)) == NULL)
    return (1);
  if (status == 1)
    if ((fdp[5] = open(word, O_WRONLY | O_TRUNC | O_CREAT, 0644)) == -1)
      return (1);
  if (status == 2)
    if ((fdp[5] = open(word, O_WRONLY | O_APPEND | O_CREAT, 0644)) == -1)
	return (1);
  return (0);
}
