/*
** my_strncmp.c for strcmp in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Sat Apr  2 20:38:43 2016 Poc
** Last update Sat Apr  2 21:29:34 2016 Poc
*/

int	my_strncmp(char *str1, char *str2, int nb)
{
  int	i;

  i = 0;
  while (str1[i] && str2[i] && i < nb - 1)
    {
      if (str1[i] != str2[i])
	return (str1[i] - str2[i]);
      i++;
    }
  return (str1[i] - str2[i]);
}
