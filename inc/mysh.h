/*
** mysh.h for mysh in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Mar 29 17:45:52 2016 Poc
** Last update Mon Apr  4 15:49:19 2016 Poc
*/

#ifndef _MYSH_
# define _MYSH_

typedef struct	s_pipes
{
  char		**command;
}		t_pipes;

typedef struct	s_args
{
  char		*args;
  char		**pathed_args;
  t_pipes	pipes;
  struct s_args	*next;
}		t_args;

/*
** PARSING
*/
char		**get_path(char **);
char		**pathing_args(char **, t_args *);
int		calc(t_args *, char **);
int		cut_by_semicolon(t_args *, char *);
int		core(t_args *, char **);
int		count_pipes(char *);
int		get_pipes(t_args *);

/*
** MINISHELL
*/
int		minishell(char **);
t_args		*parsing(char *);
char		*read_it();
void		free_all(char **, char *);

/*
** LIB
*/
char		**epur_tab(char **);
char		**copy_env(char **);
char		**str_wordtab(char *, char);
char		*my_strdup(char *);
char		*epur_str(char *);
int		arlen(char **);
int		my_strlen(char *);
int		my_strncmp(char *, char *, int);
void		my_strcat(char *, char *);
void		my_strcpy(char *, char *);
void		showtab(char **);
void		free_args(t_args *);
void		free_tab(char **);
void		free_all(char **, char *);

/*
** LINKED LIST
*/
int		cut_by_semicolon(t_args *, char *);
t_args		*add_to_back(t_args *, char *);
t_args		*create_argument_list();
void		showlist(t_args *);


#endif	/* !_MYSH_ */
