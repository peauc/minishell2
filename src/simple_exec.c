/*
** simple_exec.c for simple exec in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Apr  5 19:30:28 2016 Poc
** Last update Tue Apr 12 01:59:13 2016 Poc
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include "mysh.h"

int	prepare_single_exec(char **pipe, int *fd)
{
  char	*word;
  int	ret;
  int	status;

  if ((get_first_redirection(&(pipe[0]), &fd)) ||
      (ret = find_right_redirection(pipe[0], &status)) == -1)
    return (1);
  if (ret == -2)
    return (0);
  if ((pipe[0] = remove_right_redit(pipe[0])) == NULL ||
      (word = get_next_word(pipe[0])) == NULL)
    return (1);
  if (status == 1 &&
      (fd[3] = open(word, O_WRONLY | O_TRUNC | O_CREAT, 0644)) == -1)
    return (1);
  if (status == 2 &&
      (fd[3] = open(word, O_WRONLY | O_APPEND | O_CREAT, 0644)) == -1)
    return (1);
  return (0);
}

int	execute_it(int *fd, char **new_tab, char **ae)
{
  if ((dup2(fd[2], 0)) == -1 ||
      dup2(fd[3], 1) == -1)
    exit(1);
  if (execve(new_tab[0], new_tab, ae) == -1)
    exit(1);
  exit(1);

}

int	simple_exec(char **pipe, char ***ae)
{
  int	chid;
  int	status;
  int	*fd;
  char	*tmp;
  char	**new_tab;

  if ((fd = malloc(sizeof(int) * 4)) == NULL ||
      (tmp = my_strdup(pipe[0])) == NULL)
    return (1);
  fd[2] = 0;
  fd[3] = 1;
  prepare_single_exec(&(pipe[0]), fd);
  if ((new_tab = str_wordtab(pipe[0], ' ')) == NULL ||
      ((new_tab[0] = test_access(new_tab[0], get_path(*ae)))) == NULL)
    return (1);
  if ((chid = fork()) == -1)
    return (1);
  if ((chid == 0) && (execute_it(fd, new_tab, *ae)))
    return (1);
  else
    waitpid(chid, &status, 0);
  pipe[0] = tmp;
  return (0);
}
