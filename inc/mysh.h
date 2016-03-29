/*
** mysh.h for mysh in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Mar 29 17:45:52 2016 Poc
** Last update Tue Mar 29 19:07:40 2016 Poc
*/

#ifndef _MYSH_
# define _MYSH_


/*
** MINISHELL
*/
int	minishell(int , char **, char **);

/*
** LIB
*/
char	**copy_env(char **);
char	**str_wordtab(char *, char);
char	*my_strdup(char *);
char	*epur_str(char *);
int	arlen(char **);
int	my_strlen(char *);
void	my_strcpy(char *, char *);
void	showtab(char **);
#endif	/* !_MYSH_ */
