/*
** environ_parsing.c for environ_parsing in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Thu Apr  7 12:57:17 2016 Poc
** Last update Sat Apr  9 01:01:57 2016 Poc
*/

#include <stdlib.h>
#include <mysh.h>

char	*env_value(char **environ, char *variable)
{
  int	i;
  char	*str;

  i = 0;
  while (environ[i])
    {
      if (my_strncmp(environ[i], variable, my_strlen(variable)) == 0)
	{
	  str = my_strdup(environ[i] + my_strlen(variable));
	  return (str);
	}
      i++;
    }
  return (NULL);
}

char	**create_new_entry(char **ae, char *entry, char *value)
{
  char	**new_env;
  int	i;

  i = 0;
  if ((new_env = malloc(sizeof(char *) * (arlen(ae) + 2))) == NULL)
      return (NULL);
  while (i < arlen(ae) - 1)
    {
      if ((new_env[i] = malloc(sizeof(char) * (my_strlen(ae[i]) + 1))) == NULL)
	return (NULL);
      my_strcpy(new_env[i], ae[i]);
      i++;
    }
  if ((new_env[i] = malloc(sizeof(char) * (1 + my_strlen(entry) +
					   my_strlen(value)))) == NULL)
    return (NULL);
  my_strcpy(new_env[i], entry);
  my_strcat(new_env[i], value);
  new_env[i + 1] = NULL;
  free_tab(ae);
  return (new_env);
}

int	change_env_value(char **ae, char *field, char *newfield)
{
  int	i;

  i = 0;
  while (ae[i])
    {
      if (my_strncmp(ae[i], newfield, my_strlen(field)) == 0)
	{
	  free(ae[i]);
	  ae[i] = newfield;
	  return (0);
	}
      i++;
    }
  return (1);
}

int	create_and_fill_value(char ***ae, char *entry, char *value, char **dest)
{
  if (!(value))
    return (1);
  if ((*ae = create_new_entry(*ae, entry, value)) == NULL ||
      (*dest = env_value(*ae, "PWD=")) == NULL)
    return (1);
  return (0);
}

int	get_pos_of_value(char *field, char **ae)
{
  int	i;

  i = 0;
  while (ae[i])
    {
      if (my_strncmp(field, ae[i], my_strlen(field)) == 0)
	return (i);
      i++;
    }
  return (-1);
}
