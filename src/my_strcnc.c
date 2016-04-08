/*
** my_strcnc.c for cnc in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Fri Apr  8 20:20:19 2016 Poc
** Last update Fri Apr  8 23:09:04 2016 Poc
*/

#include <stdlib.h>
#include "mysh.h"

char	*my_strcnc(char *str1, char *str2)
{
  char	*new_chain;

  if ((new_chain = malloc(sizeof(char) *
			  (my_strlen(str1) + my_strlen(str2) + 1))) == NULL)
    return (NULL);
  my_strcpy(new_chain, str1);
  my_strcat(new_chain, str2);
  return (new_chain);
}
