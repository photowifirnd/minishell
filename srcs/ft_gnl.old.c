#include "../includes/minishell.h"

int	ft_gnl(char **line)
{
	static char	*gnl;
	char		buff[1025];
	char		*tmp1;
	char		*tmp2;
	int		data;

	if (!line)
		return (-1);
	while ((ft_strchr(gnl, '\n')) == NULL)
	{
		data = read(0, buff, 1024);
		if (data < 0)
			return (-1);
		if (!data)
			break ;
		buff[data] = '\0';
		if (!gnl)
			gnl = ft_strdup(buff);
		else
		{
			tmp1 = ft_strjoin(gnl, buff);
			free(gnl);
			gnl = tmp1;
		}
	}
	if (!data && !gnl)
	{
		gnl = ft_strdup("");
		return (0);
	}
	if ((tmp1 = ft_strchr(gnl, '\n')))
	{
		*tmp1 = 0;
		*line = ft_strdup(gnl);
		tmp2 = ft_strdup(++tmp1);
		free(gnl);
		gnl = tmp2;
	}
	else
	{
		*line = ft_strdup(gnl);
		free(gnl);
		gnl = NULL;
		return (0);
	}
	return (1);
}
