/*
** calc.c for calc in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Mon Apr  4 14:03:45 2016 Poc
** Last update Tue Apr  5 01:53:41 2016 Poc
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
  showtab(new_command);
  if ((another_tmp = test_access(new_command[0], path)) != NULL)
    {
      new_command[0] = another_tmp;
      return (new_command);
    }
  free_tab(new_command);
  return (NULL);
}

int		 fork_it(int fdp[2], char **pipes, int i, char **path)
{
  char		**get_access;

  printf("-----NEWPIPE-----\n");
  if (!(get_access = prepare_it(pipes[i], path)))
    return (werror(pipes[i]), werror(" : Command not found\n"), 0);
  printf("Command -> %s\n", get_access[0]);
  showtab(get_access + 1);
  /* char		buffer[4096]; */
  /* int		chpid; */
  /* chpid = fork(); */
  /* if (chpid == 0) */
  /*   { */
  /*     if ((dup2(0, fdp[1])) == -1 || */
  /* 	  dup2(1, fdp[0] == -1)) */
  /* 	return (1); */
  /*     execve(get_access[0], get_access, NULL); */
  /*   } */
  /* else */
  /*   { */
  /*     sleep(1); */
  /*     if (pipes[i + 1] == NULL) */
  /* 	{ */
  /* 	  read(fdp[0], buffer, 4095); */
  /* 	  write(1, buffer, my_strlen(buffer)); */
  /* 	} */
  /*   } */
  free_tab(get_access);
  return (0);
}

int		calc(t_args *args, char **ae)
{
  char		**path;
  char		**tmp_path;
  int		fdp[2];
  int		i;

  printf("\n\n\nhello its me\n");
  if ((path = get_path(ae)) == NULL)
    return (1);
  i = 0;
  printf("-----NEW_COMMAND-----\n");
  if ((pipe(fdp)) != 0)
  	return (1);
  while (args->pipes.command[i])
    {
      if (fork_it(fdp, args->pipes.command, i, path))
	return (1);
      i++;
    }
  free_tab(path);
  return (0);
}
