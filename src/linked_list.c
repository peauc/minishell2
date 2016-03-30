/*
** linked_list.c for create in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Wed Mar 30 18:48:26 2016 Poc
** Last update Wed Mar 30 18:52:29 2016 Poc
*/

#include <stdlib.h>
#include "mysh.h"

t_args	*create_argument_list()
{
  t_args	*args;

  if (!(args = malloc(sizeof(t_args))))
    return (NULL);
  args->next = NULL;
  args->args = NULL;
  return (args);
}
