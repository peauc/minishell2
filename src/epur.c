/*
** epur.c for sh in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Sat Apr  2 16:25:58 2016 Poc
** Last update Sat Apr  2 16:39:43 2016 Poc
*/

#include <stdlib.h>
#include <stdio.h>
#include "mysh.h"

char	*epur_str(char *str)
{
  int	i;
  int	k;
  char	*new_str;

  k = 0;
  i = 0;
  if (str == NULL)
    return (NULL);
  if ((new_str = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return (NULL);
  while ((str[i] == 32 || str[i] == '\t') && str[i++] != 0);
  while (str[i])
    {
      if (str[i] == '\t')
	str[i] = ' ';
      while (str[i] == 32 && str[i + 1] != 0 && str[i + 1] == 32)
	i++;
      new_str[k++] = str[i++];
    }
  if (new_str[k - 1] == 32)
    new_str[k - 1] = 0;
  new_str[k] = 0;
  free(str);
  return (new_str);
}

char	**epur_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      if ((tab[i] = epur_str(tab[i])) == NULL)
	return (NULL);
      i++;
    }
  return (tab);
}
