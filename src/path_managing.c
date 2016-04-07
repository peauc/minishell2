/*
** path_managing.c for patch in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Sat Apr  2 20:12:25 2016 Poc
** Last update Thu Apr  7 02:48:08 2016 Poc
*/

#include <stdlib.h>
#include "mysh.h"

char	**concatenate_path(char *command, char **path)
{
  int	i;
  char	**tab;

  i = 0;
  if ((tab = malloc(sizeof(char *) * (arlen(path) + 1))) == NULL)
    return (NULL);
  while (i < arlen(path))
    {
      if ((tab[i] = malloc(sizeof(char) * (my_strlen(path[i]) +
					   my_strlen(command) + 2))) == NULL)
	return (NULL);
      my_strcpy(tab[i], path[i]);
      my_strcat(tab[i], "/");
      my_strcat(tab[i], command);
      i++;
    }
  tab[i] = NULL;
  return (tab);
}

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
  /* if (path != NULL) */
  /*   { */
  /*     printf("-------path------\n"); */
  /*     showtab(path); */
  /*     printf("-------path------\n"); */
  /*   } */
  return (path);
}
