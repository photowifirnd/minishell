#include "../includes/minishell.h"

static	t_list *ft_init_env_var(char *line)
{
	t_list	*tmp;

	tmp = ft_lstnew(line);
	return (tmp);
}

int	ft_setenv(t_env *env)
{
	int	fd;
	char	*line;
	t_list	*aux;

	fd = open("./conf/env.cfg", O_RDONLY);
	if (fd < 0)
		return (-1);
	while (ft_gnl(fd, &line))
	{
		aux = ft_init_env_var(line);
		ft_lstadd_front(&env->list, aux);
		free(line);
	}
	free (line);
	ft_getenv(env->list);
	return (1);
}

int	ft_getenv(t_list *lst)
{
	if (lst == NULL)
		return (2);
	while (lst)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
	}
	return (1);
}
