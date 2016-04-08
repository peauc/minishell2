/*
** unsetenv.c for unsetnev in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Fri Apr  8 23:21:21 2016 Poc
** Last update Sat Apr  9 00:38:56 2016 Poc
*/

#include <stdlib.h>
#include "mysh.h"

int	delete_from_env(char ***ae, char *name)
{
  int	i;
  int	pos;
  int	j;
  char	**new_env;

  i = 0;
  j = 0;
  if ((pos = get_pos_of_value(name, *ae)) == -1)
    return (0);
  if ((new_env = malloc(sizeof(char *) * arlen(*ae))) == NULL)
    return (1);
  while (j < arlen(*ae) - 1)
    {
      if ((new_env[j] = malloc(sizeof(char) *
			       (my_strlen((*ae)[i]) + 1))) == NULL)
	return (1);
      if (i == pos)
	  i++;
      my_strcpy(new_env[j++], (*ae)[i++]);
    }
  new_env[j] = NULL;
  free_tab(*ae);
  *ae = new_env;
  return (0);
}

int	unsetenv(char ***ae, char **command)
{
  return (0);
}
