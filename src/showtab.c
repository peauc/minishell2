/*
** showtab.c for while in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Mar 29 18:03:52 2016 Poc
** Last update Mon Apr  4 13:17:07 2016 Poc
*/

#include <unistd.h>
#include "mysh.h"

void	showtab(char **ae)
{
  int	i;

  i = 0;
  while (ae[i])
    {
      write(1, "|", 1);
      write(1, ae[i], my_strlen(ae[i]));
      write(1, "|", 1);
      write(1, "\n", 1);
      i++;
    }
}
