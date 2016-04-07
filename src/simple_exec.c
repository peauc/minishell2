/*
** simple_exec.c for simple exec in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Apr  5 19:30:28 2016 Poc
** Last update Thu Apr  7 10:42:45 2016 Poc
*/

#include <sys/wait.h>
#include <unistd.h>
#include "mysh.h"

int	simple_exec(char **pipe, char **ae)
{
  int	chid;
  int	status;

  /* printf("----SIMPLE EXEC ----\n"); */
  /* showtab(pipe); */
  if ((chid = fork()) == -1)
    return (1);
  if (chid == 0)
    {
      if (execve(pipe[0], pipe, ae) == -1)
	return (1);
    }
  else
    wait(&status);
  return (0);
}
