/*
** wordtab.c for word in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Mar 29 18:37:30 2016 Poc
** Last update Tue Mar 29 20:37:06 2016 Poc
*/

#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"

int	count_word(char *str, int target)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i])
    {
      if (str[i] == target)
	  count++;
      i++;
    }
  return (count + 1);
}

int	get_lenght(char *str, int target)
{
  int	i;

  i = (str[0] == target ? 1 : 0);
  while (str[i])
    {
      if (str[i] == target)
	return (i);
      i++;
    }
  return (i);
}

void	my_strcpy_to_target(char *dest, char *src, char target)
{
  int	i;

  if (src[0] == target)
    src = src + 1;
  i = 0;
  while (src[i] && src[i] != target)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = 0;
}

char	**str_wordtab(char *str, char target)
{
  int	i;
  int	j;
  char	**tab;

  if ((str = epur_str(str)) == NULL ||
      (tab = malloc(sizeof(char *) * (count_word(str, target) + 1))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (str[i])
    {
      if (str[i] == target || i == 0)
	{
	  if ((tab[j] = malloc(sizeof(char) *
			       (get_lenght(str + i, 32) + 1))) == NULL)
	    return (NULL);
	  my_strcpy_to_target(tab[j], str + i, 32);
	  j++;
	}
      i++;
    }
  return (tab);
}
