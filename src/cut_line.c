/*
** cut_line.c for cut in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Wed Mar 30 19:01:07 2016 Poc
** Last update Thu Mar 31 14:54:46 2016 Poc
*/

#include <stdlib.h>
#include "mysh.h"

int	cut_by_semicolon(t_args *arguments, char *line)
{
  char	**tab;
  char	**tmp;
  int	i;

  i = 0;
  tab = str_wordtab(line, ';');
  while (tab[i])
    {
      if ((tab[i] = epur_str(tab[i])) == NULL)
	return (1);
      if ((tmp = str_wordtab(tab[i], ' ')) == NULL)
	return (1);
      if ((!add_to_back(arguments, tmp)))
	return (1);
      i++;
    }
  free(tab);
  showlist(arguments);
  return (0);
}
