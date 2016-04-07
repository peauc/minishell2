/*
** environ_parsing.c for environ_parsing in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Thu Apr  7 12:57:17 2016 Poc
** Last update Thu Apr  7 15:19:04 2016 Poc
*/

#include <stdlib.h>
#include <mysh.h>

char	*env_value(char **environ, char *variable)
{
  int	i;

  i = 0;
  while (environ[i])
    {
      if (my_strncmp(environ[i], variable, my_strlen(variable)) == 0)
	return (my_strdup(environ[i] + my_strlen(variable)));
      i++;
    }
  return (NULL);
}

int	create_new_entry(char **ae, char *entry)
{
  return (0);
}
