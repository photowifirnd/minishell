#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_command
{
	char	*command;
	char	**args;
}		t_command;
typedef struct	s_builtcmd
{
	char	*cmd;
	void	(*f)(const char *fstr);
}		t_builtcmd;
typedef struct	s_env
{
		char *pwd;
}		t_env;

void		ft_echo(const char *fstr);
void		ft_cd(const char *fstr);
int		ft_pwd(void);
void		ft_export(const char *fstr);
void		ft_unset(const char *fstr);
void		ft_env(const char *fstr);
int		ft_exit(t_command *cmd);
void		ft_setpwd(t_env *env);
int		ft_gnl(char **line);
void		ft_get_args(char *line, t_command *cmd);
int		ft_exec_command(t_command *cmd);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *str);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strchr(char *str, char c);
char		*ft_strsub(const char *str, unsigned int start, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
#endif
