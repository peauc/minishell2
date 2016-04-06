/*
** calc.c for calc in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Mon Apr  4 14:03:45 2016 Poc
** Last update Wed Apr  6 02:50:08 2016 Poc
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
  if (access(command, X_OK) == 0)
    {
      printf("i've found the command master \n");
      return (command);
    }
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
  int		i;

  i = 0;
  if ((tmp = my_strdup(command)) == NULL ||
      (new_command = str_wordtab(tmp, ' ')) == NULL)
    return (NULL);
  if ((another_tmp = test_access(new_command[0], path)) != NULL)
    {
      new_command[0] = another_tmp;
      return (new_command);
    }
  free_tab(new_command);
  return (NULL);
}

int		execute_and_pipe(int **fdp, char **pipes, char **ae, int i)
{
  if (i == 0)
    {
      if (execute_first(pipes, ae, i, fdp))
	return (1);
    }
  else if (fdp[i] == NULL)
    {
      if (execute_last(pipes, ae, i, fdp))
	return (1);
    }
  else
    {
      if (execute_middle(pipes, ae, i, fdp))
	return (1);
    }
  return (0);
}

int		 fork_it(int **fdp, char **pipes, int i, char **path, char **ae)
{
  char		**get_access;

  printf("-----NEWPIPE-----\n");
  if (!(get_access = prepare_it(pipes[i], path)))
    return (werror(pipes[i]), werror(" : Command not found\n"), 0);
  if (fdp[0] == NULL)
    {
      if (simple_exec(get_access, ae))
	return (1);
    }
  else
    if (execute_and_pipe(fdp, get_access, ae, i))
      return (1);
  free_tab(get_access);
  return (0);
}

int		calc(t_args *args, char **ae)
{
  char		**path;
  int		**fdp;
  int		i;

  printf("\n\n\nhello its me\n");
  if (((path = get_path(ae)) == NULL) |
      ((fdp = make_pipe_tab(args)) == NULL))
    return (1);
  i = arlen(args->pipes.command) - 1;
  printf("-----NEW_COMMAND-----\n");
  while (i >= 0)
    {
      if (fork_it(fdp, args->pipes.command, i, path, ae))
	return (1);
      i--;
    }
  close_fpd(fdp);
  free_tab(path);
  return (0);
}
