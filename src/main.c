/*
** main.c for  in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Mar 29 17:48:43 2016 Poc
** Last update Mon Apr  4 13:02:47 2016 Poc
*/

#include <unistd.h>
#include "mysh.h"

int	main(int ac, char **av, char **ae)
{
  char	**env;

  if (!ae[0])
    return (write(2, "No environement detected\n", 25) - 24);
  if ((env = copy_env(ae)) == NULL)
    return (1);
  if ((minishell(env)))
    return (1);
  return (0);
}
