/*
** find_redirection.c for fnd in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Sat Apr  9 16:32:09 2016 Poc
** Last update Sat Apr  9 16:34:48 2016 Poc
*/

int	find_left_redirection(char *first)
{
  int	i;

  i = 0;
  while (first[i])
    {
      if (first[i] == '<' && first[i + 1] != '<')
	return (i);
      i++;
    }
  return (-1);
}
