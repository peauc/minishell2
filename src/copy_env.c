/*
** copy_env.c for envcpy in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Mar 29 17:51:05 2016 Poc
** Last update Tue Mar 29 18:20:23 2016 Poc
*/

#include <stdlib.h>
#include <stdio.h>
#include "mysh.h"

char	**copy_env(char **ae)
{
  char	**env;
  int	i;

  i = 0;
  if ((env = malloc((arlen(ae) + 1) * sizeof(char *))) == NULL)
    return (NULL);
  while (ae[i])
    {
      if ((env[i] = malloc((my_strlen(ae[i]) + 1) * sizeof(char))) == NULL)
	return (NULL);
      my_strcpy(env[i], ae[i]);
      i++;
    }
  env[i] = NULL;
  return (env);
}
