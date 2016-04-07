/*
** cd.c for cd in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Thu Apr  7 11:07:39 2016 Poc
** Last update Thu Apr  7 15:20:42 2016 Poc
*/

#include <unistd.h>
#include "mysh.h"

int	update_cwd(char ***ae)
{
  char	*old_pwd;
  char	*new_oldpwd;
  char	*new_pwd;
  char	*pwd;

  if ((pwd = env_value(*ae, "PWD=")) == NULL)
    {
      create_new_entry(*ae, "PWD=");
    }
  if ((new_oldpwd = malloc(sizeof(char) * (my_strlen(pwd) +
					   my_strlen("OLDPWD=") + 1))) == NULL)
      return (NULL);
  my_strcpy(new_oldpwd, "OLDPWD=");
  my_strcat(new_oldpwd, pwd);

  printf("pwd %s\nold %s\nnew_old %s\n", pwd, old_pwd, new_oldpwd);
  return (0);
}

int	cd_to_home(char ***ae)
{
  char	*home;

  if ((home = env_value(*ae, "HOME=")) == NULL ||
      chdir(home) == -1)
    return (werror("No home directory found\n"), 1);
  return (0);
}

int	cd(char **tab, char ***ae)
{
  printf("%s\n", getcwd(NULL, 0));
  showtab(tab);
  if (tab[1] == NULL || (my_strcmp(tab[1], "~") && tab[2] == NULL) == 0)
    {
      if (cd_to_home(ae))
	return (1);
    }
  if (chdir(tab[1]) == -1)
    return (1);
  update_cwd(ae);
  free_tab(tab);
  return (0);
}
