/*
** simple_exec.c for simple exec in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Apr  5 19:30:28 2016 Poc
** Last update Tue Apr  5 19:37:31 2016 Poc
*/

int	simple_exec(char **pipe, char **ae)
{
  int	chid;
  int	status;

  printf("----SIMPLE EXEC ----\n");
  showtab(pipe);
  chid = fork();
  if (chid == 0)
    {
      execve(pipe[0], pipe, ae);
    }
  else
    wait(&status);
  return (0);
}
