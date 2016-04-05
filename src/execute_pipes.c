/*
** execute_pipes.c for pipes in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Apr  5 19:05:49 2016 Poc
** Last update Tue Apr  5 19:44:10 2016 Poc
*/

#include <stdio.h>
#include "mysh.h"

int	execute_first(char **command, char **env, int i, int **fdp)
{
  int	chid;
  int	status;

  printf("Execute first -> %s\n", command[0]);
  chid = fork();
  if (chid == 0)
    {
      close(fdp[0][0]);
      dup2(1, fdp[0][1]);
      execve(command[0], command, env);
    }
  /* else */
  /*   wait(&status); */
  return (0);
}

int	execute_middle(char **command, char **env, int i, int **fdp)
{
  return (0);
}

int	execute_last(char **command, char **env, int i, int **fdp)
{
  int	chid;
  int	status;

  printf("Execute last -> %s\n", command[0]);
  chid = fork();
  if (chid == 0)
    {
      close (fdp[i][1]);
      dup2(0, fdp[i - 1][0]);
      execve(command[0], command, env);
    }
  /* else */
  /*   wait(&status); */
  return (0);
}
