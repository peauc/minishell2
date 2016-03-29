/*
** my_strlen.c for my_strlen in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Mar 29 18:07:22 2016 Poc
** Last update Tue Mar 29 18:07:53 2016 Poc
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
