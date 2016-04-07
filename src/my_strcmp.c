/*
** my_strcmp.c for cmp in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Thu Apr  7 13:57:02 2016 Poc
** Last update Thu Apr  7 13:58:30 2016 Poc
*/

int	my_strcmp(char *str, char *str2)
{
  int	i;

  i = 0;
  while (str[i] && str2[i] && str[i] == str2[i])
      i++;
  return (str[i] - str2[i]);
}
