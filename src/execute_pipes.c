/*
** execute_pipes.c for pipes in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Apr  5 19:05:49 2016 Poc
** Last update Wed Apr  6 02:37:56 2016 Poc
*/

#include <sys/wait.h>
#include <unistd.h>
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
      dup2(fdp[0][1], 1);
      execve(command[0], command, env);
    }
  else
    {
      wait(&status);
    }
  return (0);
}

int	execute_middle(char **command, char **env, int i, int **fdp)
{
  int	chid;
  int	status;

  printf("Execute middle -> %s\n", command [0]);
  chid = fork();
  if (chid == 0)
    {
      printf("i = %d\n", i);
      close (fdp[i - 1][1]);
      close (fdp[i][0]);
      dup2(fdp[i - 1][0], 0);
      dup2(fdp[i][1], 1);
      execve(command[0], command, env);
    }
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
      close (fdp[i - 1][1]);
      dup2(fdp[i - 1][0], 0);
      execve(command[0], command, env);
    }
  return (0);
}
