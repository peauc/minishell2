/*
** main.c for main in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishell1
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Thu Jan  7 16:29:47 2016
** Last update Sat Apr  9 02:58:10 2016 Poc
*/

#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"

char		*read_it()
{
  int		i;
  int		readed;
  char		*line;

  write(1, "?> ", 3);
  if ((line = malloc(4096 * sizeof(char))) == NULL)
    return (NULL);
  if (((readed = read(0, line, 4096)) <= 0))
    {
      free(line);
      return (write(1, "exit\n", 5), NULL);
    }
  i = -1;
  line[readed - 1] = (line[readed - 1] == 10 ? 0 : line[readed - 1]);
  line[readed] = 0;
  while (line[++i] != 0 && line[i] != 10)
    {
      if (line[i] == 10)
	line[i] = 0;
      if (line[i] == '\t')
	line[i] = ' ';
    }
  return (line);
}
