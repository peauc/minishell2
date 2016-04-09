/*
** my_strcpy.c for mystrcpy in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Mar 29 18:08:34 2016 Poc
** Last update Sat Apr  9 16:06:24 2016 Poc
*/

void	my_rev_strcpy_target(char *dest, char *src, char target)
{
  int	i;
  int	j;

  j = 0;
  i = my_strlen(src);
  while (src && src[i] != target)
      i--;
  i++;
  while (src[i] && src[i] != target)
    {
      dest[j++] = src[i++];
    }
  dest[j] = 0;
}

void	my_strcpy_target(char *dest, char *src, char target)
{
  int	i;

  i = 0;
  while (src && src[i] != target)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = 0;
}

void	my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = 0;
}
