/*
** builtin.c for builtin in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Thu Apr  7 10:23:09 2016 Poc
** Last update Fri Apr  8 17:29:43 2016 Poc
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

int		joyeuse_fonction(char **pipe, char ***ae)
{
  return (0);
}

int		builtin_while(char **dico, char *tmp,
			      int (*ftab[6])(char **, char ***), char ***ae)
{
  int		i;
  char		**tab;

  i = 0;
  while (dico[i])
    {
      if (my_strncmp(dico[i], tmp, my_strlen(dico[i])) == 0)
	{
	  if ((tab = str_wordtab(tmp, 32)) == NULL)
	    return (1);
	  else
	    return (free_tab(dico), ftab[i](tab, ae));
	}
      i++;
    }
  return (2);
}

int		is_it_a_builtin(char *command, char ***ae)
{
  char		**dico;
  int		(*ftab[6])(char **, char ***);
  int		i;
  char		*tmp;
  int		ret;

  i = 0;
  ret = 0;
  if ((dico = make_dico()) == NULL ||
      (tmp = my_strdup(command)) == NULL)
    return (1);
  ftab[0] = cd;
  ftab[1] = env;
  ftab[2] = joyeuse_fonction;
  ftab[3] = joyeuse_fonction;
  ftab[4] = joyeuse_fonction;
  if ((ret = builtin_while(dico, tmp, ftab, ae)) == 1)
    return (1);
  else if (ret == 0)
    return (0);
  return (free(tmp), free_tab(dico), 2);
}
