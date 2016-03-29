/*
** malloc_error.c for mallocerror in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Mar 29 18:24:03 2016 Poc
** Last update Tue Mar 29 18:24:35 2016 Poc
*/

int	malloc_error()
{
  write(1, "Malloc error\n", 13);
  return (1);
}
