/*
** cut_line.c for cut in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Wed Mar 30 19:01:07 2016 Poc
** Last update Sat Apr  9 12:24:08 2016 Poc
*/

#include <stdlib.h>
#include "mysh.h"

int	check_pipes(char *line)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (line[i])
    {
      if (line[i] == '|')
	count++;
      if (count >= 2)
	return (1);
      if (line[i] != '|' && line[i] != ' ')
	count = 0;
      i++;
    }
  if (count != 0)
    return (1);
  return (0);
}

int	error_gestion(char *line)
{
  if (check_pipes(line))
    return (werror("Invalid null command.\n"), 1);
  return (0);
}

int	cut_by_semicolon(t_args *arguments, char *line)
{
  char	**tab;
  int	i;

  i = 0;
  line = epur_str(line);
  if (error_gestion(line))
    return (1);
  tab = str_wordtab(line, ';');
  while (tab[i])
    {
      if ((tab[i] = epur_str(tab[i])) == NULL)
	return (1);
      if ((!add_to_back(arguments, tab[i])))
	return (1);
      i++;
    }
  free(tab);
  return (0);
}
