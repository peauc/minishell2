/*
** validate_string.c for string in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Fri Apr  8 19:10:31 2016 Poc
** Last update Sat Apr  9 00:13:17 2016 Poc
*/

int	is_valid_char(char name, char *dictionary)
{
  int	i;

  i = 0;
  while (dictionary[i])
    {
      if (dictionary[i] == name)
	return (0);
      i++;
    }
  return (1);
}

int     verify_name(char *name, char *dictionary)
{
  int   i;

  i = 0;
  while (name[i])
    {
      if (is_valid_char(name[i], dictionary))
	return (1);
      i++;
    }
  return (0);
}
