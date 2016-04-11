/*
** execute_pipes.c for pipes in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Apr  5 19:05:49 2016 Poc
** Last update Sun Apr 10 19:16:21 2016 Poc
*/

#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include "mysh.h"

#include <sys/stat.h>
#include <fcntl.h>

int	execute_first(char **command, char **env, int i, int **fdp)
{
  int	chid;
  int	status;

  if ((chid = fork()) == -1)
    return (1);
  if (chid == 0)
    {
      if ((close(fdp[i][0]) == -1) ||
	  (dup2(fdp[i][1], 1) == -1) ||
	  (dup2(fdp[i][2], 0) == -1) ||
	  (execve(command[0], command, env)) == -1)
	  return (1);
    }
  if (waitpid(chid, &status, 0) == -1)
    return (1);
  return (0);
}

int	execute_middle(char **command, char **env, int i, int **fdp)
{
  int	chid;
  int	status;

  if ((chid = fork()) == -1)
    return (1);
  if (chid == 0)
    {
      if ((close(fdp[i - 1][1])) == -1 ||
	  (close(fdp[i][0])) == -1 ||
	  (dup2(fdp[i - 1][0], 0)) == -1 ||
	  (dup2(fdp[i][1], 1)) == -1 ||
	  (execve(command[0], command, env)) == -1)
	  return (1);
    }
  if (close(fdp[i - 1][1]) == -1 ||
      close(fdp[i - 1][0]) == -1 ||
      waitpid(chid, &status, 0) == -1)
    return (0);
  return (0);
}

int	execute_last(char **command, char **env, int i, int **fdp)
{
  int	chid;
  int	status;

  if ((chid = fork()) == -1)
    return (1);
  if (chid == 0)
    {
      if ((close (fdp[i - 1][1])) == -1 ||
	  (dup2(fdp[i - 1][0], 0)) == -1 ||
	  (dup2(fdp[0][5], 1)) == -1 ||
	  (execve(command[0], command, env) == -1))
	return (1);
    }
  close(fdp[i - 1][1]);
  close(fdp[i - 1][0]);
  waitpid(chid, &status, 0);
  return (0);
}
