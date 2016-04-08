/*
** linked_list.c for create in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Wed Mar 30 18:48:26 2016 Poc
** Last update Fri Apr  8 23:08:32 2016 Poc
*/

#include <unistd.h>
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

t_args		*add_to_back(t_args *args, char *line)
{
  t_args	*tmp;

  if (args->args == NULL)
    {
      args->args = line;
      return (args);
    }
  while (args->next != NULL)
    args = args->next;
  if ((tmp = malloc(sizeof(t_args))) == NULL)
    return (NULL);
  tmp->next = NULL;
  tmp->args = line;
  args->next = tmp;
  return (tmp);
}

void		showlist(t_args *args)
{
  while (args)
    {
      write(1, args->args, my_strlen(args->args));
      args = args->next;
    }
}
