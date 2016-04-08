/*
** make_new_env_var.c for new_env_var in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Thu Apr  7 18:27:33 2016 Poc
** Last update Fri Apr  8 13:39:06 2016 Poc
*/

#include <stdlib.h>
#include "mysh.h"

char	*make_new_env_var(char *field, char *value)
{
  char	*new_chain;

  if ((new_chain = malloc(sizeof(char) *
			  (my_strlen(field) + my_strlen(value) + 1))) == NULL)
       return (NULL);
  my_strcpy(new_chain, field);
  my_strcat(new_chain, value);
  return (new_chain);
}
