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

int		ft_gnl(char **line);
void		ft_get_args(char *line, t_command *cmd);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *str);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strchr(char *str, char c);
char		*ft_strsub(const char *str, unsigned int start, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
#endif
