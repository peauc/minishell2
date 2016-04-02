/*
** count_in_wordtab.c for count in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Thu Mar 31 18:58:14 2016 Poc
** Last update Sat Apr  2 15:54:07 2016 Poc
*/

int	count_pipes(char *tab)
{
  int	i;
  int	count;

  count = 0;
  i = 0;
  while (tab[i])
    {
      if (tab[i] == '|')
	count++;
      i++;
    }
  return (count);
}
