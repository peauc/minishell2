/*
** core.c for core in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Sat Apr  2 18:26:36 2016 Poc
** Last update Sat Apr  2 21:56:36 2016 Poc
*/

#include <stdlib.h>
#include "mysh.h"

int	core(t_args *args, char **ae)
{
  char	**path;

  if ((path = get_path(ae)) == NULL)
    return (1);

  free_tab(path);
  return (0);
}
