/*
** mysh.h for mysh in /home/peau_c/rendu/PSU/PSU_2015_minishell2
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Mar 29 17:45:52 2016 Poc
** Last update Sat Apr  9 00:40:43 2016 Poc
*/

#ifndef _MYSH_
# define _MYSH_

# include <stdio.h>
# define VALID "abcdefghijklmnoparstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 "

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
int		simple_exec(char **, char ***);

/*
** MINISHELL
*/
int		calc(t_args *, char ***);
int		core(t_args *, char ***);
int		minishell(char **);
t_args		*parsing(char *);
char		*read_it();
void		close_fdp(int **);
void		free_all(char **, char *);

/*
** LIB
*/
char		**epur_tab(char **);
char		**copy_env(char **);
char		**str_wordtab(char *, char);
char		*my_strcnc(char *, char *);
char		*my_strdup(char *);
char		*epur_str(char *);
int		arlen(char **);
int		my_strlen(char *);
int		my_strcmp(char *, char *);
int		my_strncmp(char *, char *, int);
int		verify_name(char *, char *);
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

/*
** ENVIRON PARSING
*/
char		*env_value(char **, char *);
char		**create_new_entry(char **, char *, char *);
char		*make_new_env_var(char *, char *);
int		change_env_value(char **, char *, char *);
int		create_and_fill_value(char ***, char *, char *, char **);
int		get_pos_of_value(char *, char **);

/*
** BUILT-IN
*/
int		cd(char **, char ***);
int		env(char **, char ***);
int		setenv(char **, char ***);
int		is_it_a_builtin(char *, char ***);

#endif	/* !_MYSH_ */
