/*
** path_managing.c for patch in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Sat Apr  2 20:12:25 2016 Poc
** Last update Sat Apr  2 21:38:40 2016 Poc
*/

#include <stdlib.h>
#include "mysh.h"

char	**get_path(char **ae)
{
  char	**path;
  char	*tmp;
  int	i;

  i = -1;
  path = NULL;
  while (ae[++i])
      if (my_strncmp(ae[i], "PATH=", 5) == 0)
	{
	  if ((tmp = my_strdup(ae[i] + 5)) == NULL ||
	      (path = (str_wordtab(tmp, ':'))) == NULL)
	    return (NULL);
	  break ;
	}
  if (path != NULL)
    showtab(path);
  return (path);
}
