/*
** calc.c for calc in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Mon Apr  4 14:03:45 2016 Poc
** Last update Tue Apr  5 18:29:41 2016 Poc
*/

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
  return (0);
}

int		 fork_it(int **fdp, char **pipes, int i, char **path, char **ae)
{
  char		**get_access;
  int		chpid;
  int		status;

  status = 0;
  printf("-----NEWPIPE-----\n");
  if (!(get_access = prepare_it(pipes[i], path)))
    return (werror(pipes[i]), werror(" : Command not found\n"), 0);
  printf("Command -> %s\n", get_access[0]);
  showtab(get_access + 1);
  chpid = fork();
  if (chpid == 0)
    {
      execute_and_pipe(fdp, pipes, ae, i);
    }
  else
    {
      wait(&status);
    }
  free_tab(get_access);
  return (0);
}

int		**make_pipe_tab(t_args *args)
{
  int		**fdp;
  int		i;

  i = 0;
  if ((fdp = malloc(sizeof(int *) * (count_pipes(args->args) + 1))) == NULL)
    return (NULL);
  fdp[count_pipes(args->args)] = NULL;
  while (fdp[i])
    {
      if ((fdp[i] = malloc(sizeof(int) * 2)) == NULL)
	return (NULL);

      i++;
    }
  fdp[i] = NULL;
  return (fdp);
}

int		calc(t_args *args, char **ae)
{
  char		**path;
  char		**tmp_path;
  int		**fdp;
  int		i;

  printf("\n\n\nhello its me\n");
  printf("%d\n", count_pipes(args->args) + 2);
  if ((path = get_path(ae)) == NULL |
      ((fdp = make_pipe_tab(args)) == NULL))
    return (1);
  i = arlen(args->pipes.command) - 1;
  printf("i = %d\n", i);
  printf("-----NEW_COMMAND-----\n");
  while (i >= 0)
    {
      if (fork_it(fdp, args->pipes.command, i, path, ae))
	return (1);
      i--;
    }
  free_tab(path);
  return (0);
}
