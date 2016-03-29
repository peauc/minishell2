/*
** my_strdup.c for mystrdup in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Mar 29 19:02:19 2016 Poc
** Last update Tue Mar 29 19:08:18 2016 Poc
*/

#include <stdlib.h>
#include "mysh.h"

char	*my_strdup(char *str)
{
  char	*dup;

  if ((dup = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  my_strcpy(dup, str);
  return (dup);
}
