/*
** arlen.c for arlen in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Mar 29 17:52:58 2016 Poc
** Last update Tue Mar 29 18:10:20 2016 Poc
*/

int	arlen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}
