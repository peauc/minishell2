/*
** mysh.h for mysh in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Mar 29 17:45:52 2016 Poc
** Last update Wed Mar 30 18:54:17 2016 Poc
*/

#ifndef _MYSH_
# define _MYSH_


typedef struct	s_args
{
  char		**args;
  struct t_args	*next;
}		t_args;

/*
** MINISHELL
*/
int		minishell(char **);
t_args		*parsing(char *);

/*
** LIB
*/
char		**copy_env(char **);
char		**str_wordtab(char *, char);
char		*my_strdup(char *);
char		*epur_str(char *);
char		*read_it();
int		arlen(char **);
int		my_strlen(char *);
void		my_strcpy(char *, char *);
void		showtab(char **);

/*
** LINKED LIST
*/
t_args	*create_argument_list();

#endif	/* !_MYSH_ */
