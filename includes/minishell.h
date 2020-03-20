#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

/*************Estructura de listas para las variables de entorno**********/
typedef struct		s_list
{
	char		*content;
	struct s_list	*next;
}			t_list;
/*************Estructura de comandos**********/
typedef struct		s_command //Nombre;
{
	char		*command;
	char		**args;
	int		echo_flag;
	int		i;
	t_list		*list;
}			t_command;
/*************Estructura de comandos integrados, no usado por ahora**********/
typedef struct		s_builtcmd
{
	char		*cmd;
	void		(*f)(const char *fstr);
}			t_builtcmd;
/*************Estructura de las variables de entorno**********/
typedef struct		s_env //Nombre:
{
	char	 	*pwd;
	t_list		*list;
}			t_env; 
/*************Estructura para GET NEXT LINE**********/
typedef struct		s_file
{
	char		*strbuf;
	char		*endl;
	int		rsz;
	long		len;
	long		pos;
}			t_file;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			del(void *content);
int			ft_getenv(t_list *lst);
int			ft_setenv(t_env *env);
int			ft_echo(char *line, t_command *cmd);
void			ft_cd(const char *fstr);
int			ft_pwd(void);
int			ft_export(t_command *cmd, char *line);
void			ft_unset(const char *fstr);
void			ft_env(const char *fstr);
int			ft_exit(t_command *cmd);
void			ft_setpwd(t_env *env);
int			ft_gnl(int const fd, char **line);
void			ft_get_args(char *line, t_command *cmd);
int			ft_exec_command(t_command *cmd, char *line);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *str);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strchr(char *str, char c);
char			*ft_strsub(const char *str, unsigned int start, size_t len);
int			ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dest, const char *src);
void			*ft_memcpy(void *dest, const void *src, size_t len);
char			**ft_split(char const *s, char c);
size_t			ft_get_quotes(char *line, char c);
void			ft_settemp(char **buffer, char *line, int fr);
#endif
