/*
** calc.c for calc in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Mon Apr  4 14:03:45 2016 Poc
** Last update Tue Apr 12 01:58:20 2016 Poc
*/

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"

char		*test_access(char *command, char **path)
{
  char		**new_path;
  char		*ret;
  int		i;

  i = 0;
  if (!command)
    return (NULL);
  if (access(command, X_OK) == 0)
    {
      return (command);
    }
  if (!(path))
    return (NULL);
  new_path = concatenate_path(command, path);
  while (path[i])
    {
      if (access(new_path[i], X_OK) == 0)
	{
	  ret = my_strdup(new_path[i]);
	  free_tab(new_path);
	  return (ret);
	}
      i++;
    }
  free_tab(new_path);
  return (NULL);
}

char		**prepare_it(char *command, char **path)
{
  char		**new_command;
  char		*tmp;
  char		*another_tmp;

  if ((tmp = my_strdup(command)) == NULL ||
      (new_command = str_wordtab(tmp, ' ')) == NULL ||
      new_command[0] == NULL)
    return (NULL);
  if ((another_tmp = test_access(new_command[0], path)) != NULL)
    {
      new_command[0] = another_tmp;
      return (new_command);
    }
  free(another_tmp);
  free_tab(new_command);
  return (NULL);
}

int		execute_and_pipe(int **fdp, char **pipes, char ***ae, int i)
{
  if (i == 0)
    {
      if (execute_first(pipes, *ae, i, fdp))
	return (1);
    }
  else if (fdp[i] == NULL)
    {
      if (execute_last(pipes, *ae, i, fdp))
	return (1);
    }
  else
    {
      if (execute_middle(pipes, *ae, i, fdp))
	return (1);
    }
  return (0);
}

int		 fork_it(int **fdp, char **pipes, int i, char ***ae)
{
  char		**get_access;
  char		*tmp;
  char		**path;
  int		ret;

  path = get_path(*ae);
  if ((tmp = my_strdup(pipes[i])) == NULL)
    return (1);
  if ((ret = is_it_a_builtin(tmp, ae)) == 1)
    return (1);
  else if (ret == 0)
    return (free(tmp), 0);
  if (fdp[0] == NULL)
    {
      if (simple_exec(pipes, ae))
	return (werror(tmp), werror(" : Command not found\n"), free(tmp), 1);
      return (0);
    }
  if (!(get_access = prepare_it(pipes[i], path)))
    return (werror(tmp), werror(" : Command not found\n"), 1);
  else
    if (execute_and_pipe(fdp, get_access, ae, i))
      return (1);
  free_tab(get_access);
  return (free(tmp), 0);
}

int		calc(t_args *args, char ***ae)
{
  char		**path;
  int		**fdp;
  int		i;

  path = get_path(*ae);
  if (((fdp = make_pipe_tab(args->pipes.command)) == NULL))
      return (1);
  i= 0;
  while (i < arlen(args->pipes.command))
    {
      if (fork_it(fdp, args->pipes.command, i, ae))
	return (1);
      i++;
    }
  close_fdp(fdp);
  free_tab(path);
  return (0);
}
