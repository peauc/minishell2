/*
** simple_exec.c for simple exec in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Apr  5 19:30:28 2016 Poc
** Last update Fri Apr  8 23:09:41 2016 Poc
*/

#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "mysh.h"

int	simple_exec(char **pipe, char ***ae)
{
  int	chid;
  int	status;

  if ((chid = fork()) == -1)
    return (1);
  if (chid == 0)
    {
      if (execve(pipe[0], pipe, *ae) == -1)
	{
	  exit(1);
	  return (1);
	}
      return (1);
    }
  else
    wait(&status);
  return (0);
}
