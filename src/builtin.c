/*
** builtin.c for builtin in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Thu Apr  7 10:23:09 2016 Poc
** Last update Thu Apr  7 11:10:59 2016 Poc
*/

#include <stdlib.h>
#include <stdio.h>
#include "mysh.h"

static char	**make_dico()
{
  char		**dico;

  if ((dico = malloc(sizeof(char *) * 6)) == NULL)
    return (NULL);
  dico[5] = NULL;
  if (((dico[0] = my_strdup("cd")) == NULL) ||
      ((dico[1] = my_strdup("env")) == NULL) ||
      ((dico[2] = my_strdup("setenv")) == NULL) ||
      ((dico[3] = my_strdup("unsetenv")) == NULL) ||
      ((dico[4] = my_strdup("exit")) == NULL))
      return (NULL);
  return (dico);
}

int		joyeuse_fonction(char *pipe)
{
  printf("found ");
  return (1);
}

int		is_it_a_builtin(char *command, char **ae)
{
  char		**dico;
  char		**tab;
  int		(*ftab[6])(char **);
  int		i;

  i = 0;
  if ((dico = make_dico()) == NULL)
    return (1);
  ftab[0] = joyeuse_fonction;
  ftab[1] = joyeuse_fonction;
  ftab[2] = joyeuse_fonction;
  ftab[3] = joyeuse_fonction;
  ftab[4] = joyeuse_fonction;
  printf("%s\n", command);
  while (dico[i])
    {
      if (my_strncmp(dico[i], command, my_strlen(dico[i])) == 0)
	if ((str_wordtab(command, 32)) == NULL)
	  return (ftab[i](tab));
      i++;
    }
  return (1);
}
