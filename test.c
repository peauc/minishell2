/*
** test.c for tst in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Wed Apr  6 01:50:33 2016 Poc
** Last update Wed Apr  6 02:12:03 2016 Poc
*/

#include <stdlib.h>
#include <unistd.h>

int	main(int ac, char **av, char **ae)
{
  int	**pipes;
  /* char	**command = {"ls", "-la"}; */
  /* char	**command2 = {"wc"}; */
  char	**contain = malloc(16);
  char	**contain2 = malloc(16);
  char	*test1 = "/bin/ls";
  char	*test2 = "/bin/wc";
  char	buffer[4096];

  contain[0] = test1;
  contain[1] = NULL;
  contain2[0] = test2;
  contain2[1] = NULL;
  pipes = malloc(16);
  pipes[0] = malloc(8);
  pipes[1] = malloc(8);
  pipe(pipes[0]);
  pipe(pipes[1]);
  execute_last(contain2, ae, 1, pipes);
  execute_first(contain, ae, 0, pipes);
  return (0);
}