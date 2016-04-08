/*
** my_getnbr.c for my_getnbr in /CPE_2015_corewar/src/lib
**
** Made by Poc
** Login   <peau_c@epitech.eu>
**
** Started on  Sat Apr  8 21:35:11 2016 Poc
** Last update Sat Apr  9 01:48:38 2016 Poc
*/

int	my_getnbr(char *str)
{
  int	i;
  int	nb;
  int	signe;

  i = 0;
  nb = 0;
  signe = 1;
  while (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
    {
      if (str[i] == '-')
	signe = -(signe);
      i = i + 1;
    }
  while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
    {
      nb = (nb * 10) + (str[i] - 48);
      i = i + 1;
    }
  if (nb >= 2147483647)
    {
      return (0);
    }
  return (nb * signe);
}
