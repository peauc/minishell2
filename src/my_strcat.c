/*
** my_strcat.c for strcat in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Mon Apr  4 10:57:28 2016 Poc
** Last update Tue Apr  5 00:07:21 2016 Poc
*/

void	my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i])
    i++;
  while (src[j])
    dest[i++] = src[j++];
  dest[i] = 0;
}
