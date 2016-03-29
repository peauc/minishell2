/*
** wordtab.c for word in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Mar 29 18:37:30 2016 Poc
** Last update Tue Mar 29 19:27:39 2016 Poc
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
	{
	  count++;
	}
      i++;
    }
  return (count + 1);
}

char	**str_wordtab(char *str, char target)
{
  int	i;
  char	**tab;

  printf("%s\n", str);
  if ((str = epur_str(str)) == NULL ||
      (tab = malloc(sizeof(char *) * count_word(str, target))) == NULL)
    return (NULL);

  i = 0;
  while (str[i])
    {
      printf("%c", str[i]);
      i++;
    }
  return (tab);
}
