/*
** core.c for core in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Sat Apr  2 18:26:36 2016 Poc
** Last update Mon Apr  4 15:01:03 2016 Poc
*/

#include <stdlib.h>
#include "mysh.h"

int	core(t_args *args, char **ae)
{
  char	**path;

  while (args)
    {
      calc(args, ae);
      args = args->next;
    }
  return (0);
}
