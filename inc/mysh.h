/*
** mysh.h for mysh in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Mar 29 17:45:52 2016 Poc
** Last update Tue Apr  5 19:16:44 2016 Poc
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
char		**concatenate_path(char *, char **);
char		**get_path(char **);
char		**pathing_args(char **, t_args *);
int		**make_pipe_tab(t_args *);
int		cut_by_semicolon(t_args *, char *);
int		count_pipes(char *);
int		execute_first(char **, char **, int, int **);
int		execute_middle(char **, char **, int, int **);
int		execute_last(char **, char **, int, int **);
int		get_pipes(t_args *);


/*
** MINISHELL
*/
int		calc(t_args *, char **);
int		core(t_args *, char **);
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
void		werror(char *);

/*
** LINKED LIST
*/
int		cut_by_semicolon(t_args *, char *);
t_args		*add_to_back(t_args *, char *);
t_args		*create_argument_list();
void		showlist(t_args *);


#endif	/* !_MYSH_ */
