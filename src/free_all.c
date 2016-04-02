/*
** free_all.c for free in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Wed Mar 30 19:25:47 2016 Poc
** Last update Sat Apr  2 17:34:13 2016 Poc
*/

#include <stdlib.h>
#include "mysh.h"

void            free_args(t_args *args)
{
  t_args        *tmp;

  while (args)
    {
      tmp = args;
      free(args->args);
      args = args->next;
      free(tmp);
    }
}

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

void	free_all(char **env, char *line)
{
  free_tab(env);
  free(line);
}
