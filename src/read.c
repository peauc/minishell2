/*
** main.c for main in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishell1
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Thu Jan  7 16:29:47 2016
** Last update Wed Mar 30 17:39:17 2016 Poc
*/

#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"

char		*read_it()
{
  int		i;
  int		readed;
  char		*get_next;

  if ((get_next = malloc(4096 * sizeof(char))) == NULL)
    exit(-1);
  if (((readed = read(0, get_next, 4096)) <= 0))
    return (write(1, "exit\n", 5), NULL);
  i = -1;
  while (get_next[++i] != 0 && get_next[i] != 10)
    {
      if (get_next[i] == 10)
	get_next[i] = 0;
      if (get_next[i] == '\t')
	get_next[i] = ' ';
    }
  if (get_next[0] == 0)
    return (NULL);
  return (get_next);
}
