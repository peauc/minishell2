/*
** cd.c for cd in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Thu Apr  7 11:07:39 2016 Poc
** Last update Fri Apr  8 17:29:20 2016 Poc
*/

#include <unistd.h>
#include "mysh.h"

int	update_cwd(char ***ae)
{
  char	*old_pwd;
  char	*new_oldpwd;
  char	*pwd;
  char	*tmp;

  if (((pwd = env_value(*ae, "PWD=")) == NULL) &&
      (create_and_fill_value(ae, "PWD=", my_strdup(getcwd(NULL, 0)), &pwd)))
    return (1);
  if ((old_pwd = env_value(*ae, "OLDPWD=")) == NULL &&
      (*ae = create_new_entry(*ae, "OLDPWD=",
			      my_strdup(getcwd(NULL, 0)))) == NULL)
    return (1);
  if ((new_oldpwd = make_new_env_var("OLDPWD=", pwd)) == NULL)
    return (1);
  free(pwd);
  if ((pwd = getcwd(NULL, 0)) == -1 ||
      (tmp = make_new_env_var("PWD=", pwd)) == NULL ||
      (change_env_value(*ae, "OLDPWD=", new_oldpwd)) ||
      (change_env_value(*ae, "PWD=", tmp)))
    return (1);
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

int	cd_to_last_step(char ***ae)
{
  char	*str;

  if ((str = env_value(*ae, "OLDPWD=")) == NULL)
    return (1);
  if (chdir(str) == -1)
      return (1);
  return (0);
}

int	cd(char **tab, char ***ae)
{
  if (tab[1] == NULL || (my_strcmp(tab[1], "~") && tab[2] == NULL) == 0)
    {
      if (cd_to_home(ae))
	return (1);
      return (0);
    }
  else if ((tab[1][0] == '-') && (tab[1][1] == 0) && !(cd_to_last_step(ae)))
    return (1);
  else if (chdir(tab[1]) == -1)
    return (werror("Couldn't find directory\n"), 1);
  if (update_cwd(ae))
    return (1);
  free_tab(tab);
  return (0);
}
