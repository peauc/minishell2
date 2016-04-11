/*
** get_next_word.c for get_next in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Sat Apr  9 16:39:13 2016 Poc
** Last update Tue Apr 12 01:42:39 2016 Poc
*/

#include <stdlib.h>
#include "mysh.h"

char	*get_next_word(char *string)
{
  char	*word;
  int	i;
  int	j;

  j = 0;
  i = 0;
  if ((word = malloc(sizeof(char) * (my_strlen(string) + 1))) == NULL)
    return (NULL);
  while (string[i] && (is_valid_char(string[i], PIPE) == 1))
      i++;
  while (string[i] && string[i] != 32)
    {
      word[j++] = string[i++];
    }
  word[j] = 0;
  return (word);
}
