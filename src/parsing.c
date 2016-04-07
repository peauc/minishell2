/*
** parsing.c for parse in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Wed Mar 30 17:58:43 2016 Poc
** Last update Thu Apr  7 15:18:55 2016 Poc
*/

#include <stdlib.h>
#include "mysh.h"

t_args	*parsing(char *line)
{
  t_args	*args;

  if ((args = create_argument_list()) == NULL)
    return (NULL);
  cut_by_semicolon(args, line);
  return (args);
}
