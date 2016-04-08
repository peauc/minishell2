/*
** exit.c for exit in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Sat Apr  9 01:36:03 2016 Poc
** Last update Sat Apr  9 01:51:20 2016 Poc
*/

#include <stdlib.h>
#include "mysh.h"

int	b_exit(char **command, char ***ae)
{
  ae = ae;
  if (command[1] == NULL)
    exit(0);
  else
    exit(my_getnbr(command[2]));
  return (0);
}
