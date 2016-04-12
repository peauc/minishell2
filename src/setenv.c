/*
** setenv.c for setenv.c in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Fri Apr  8 18:31:11 2016 Poc
** Last update Tue Apr 12 02:01:17 2016 Poc
*/

#include <stdlib.h>
#include "mysh.h"

static int	change_value(char **command, char ***env)
{
  char		*new_chain;
  int		i;

  if (verify_name(command[1], VALID))
    return (werror("Only alphanumericals characters allowed\n"), 1);
  if ((new_chain = my_strcnc(command[1], "=")) == NULL)
    return (1);
  if ((i = get_pos_of_value(new_chain, *env)) != -1)
      delete_from_env(env, new_chain);
  *env = create_new_entry(*env, new_chain, command[2]);
  return (0);
}

int		setenv(char **command, char ***ae)
{
  char		*tmp;

  if (command[1] == NULL)
    {
      showtab(*ae);
      return (0);
    }
  else if (command[2] == NULL)
     {
      if (verify_name(command[1], VALID))
	return (werror("Only alphanumericals characters allowed\n"), 1);
      if ((tmp = malloc(sizeof(char) * (my_strlen(command[1]) + 2))) == NULL)
	return (1);
      my_strcpy(tmp, command[1]);
      my_strcat(tmp, "=");
      if ((delete_from_env(ae, tmp)) ||
	  ((*ae = create_new_entry(*ae, tmp, "")) == NULL))
	return (1);
      free(tmp);
    }
  else
    change_value(command, ae);
  return (0);
}
