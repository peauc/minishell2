/*
** simple_exec.c for simple exec in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Apr  5 19:30:28 2016 Poc
** Last update Mon Apr 11 23:01:14 2016 Poc
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include "mysh.h"

int	prepare_single_exec(char **pipe, int *fd)
{
  char	*new_str;
  char	*word;
  char	*last;
  int	ret;
  int	status;

  if ((get_first_redirection(&(pipe[0]), &fd)))
    return (1);
  printf("after get first %s\n", pipe[0]);
  if ((ret = find_right_redirection(pipe[0], &status)) == -1)
    return (1);
  if (ret == -2)
    return (0);
  printf("after find %s\n", pipe[0]);
  if ((pipe[0] = remove_right_redit(pipe[0])) == NULL ||
      (word = get_next_word(pipe[0] + ret)) == NULL)
      return (1);
  if (status == 1)
    {
      if ((fd[3] = open(word, O_WRONLY | O_TRUNC | O_CREAT, 0644)) == -1)
	return (1);
    }
  else if (status == 2)
    if ((fd[3] = open(word, O_WRONLY | O_APPEND | O_CREAT, 0644)) == -1)
      return (1);
  return (0);
  printf("hello %s\n", pipe[0]);
}

int	simple_exec(char **pipe, char ***ae)
{
  int	chid;
  int	status;
  int	*fd;
  char	**new_tab;

  if ((fd = malloc(sizeof(int) * 4)) == NULL)
    return (1);
  fd[2] = 0;
  fd[3] = 1;
  fd[1] = 0;
  fd[0] = 0;
  printf("Rehello %s\n", pipe[0]);
  prepare_single_exec(&(pipe[0]), fd);
  printf("pipe[0] %s\n", pipe[0]);
  new_tab = str_wordtab(pipe[0], ' ');
  new_tab[0] = test_access(new_tab[0], get_path(*ae));
  printf("Hello %d %d |%s|\n", fd[2], fd[3], new_tab[0]);
  if ((chid = fork()) == -1)
    return (1);
  if (chid == 0)
    {
      if ((dup2(fd[2], 0)) == -1 ||
	  dup2(fd[3], 1) == -1)
	return (1);
      if (execve(new_tab[0], new_tab, *ae) == -1)
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
