#include "../includes/minishell.h"

size_t	ft_get_quotes(char *line, char c)
{
	size_t	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == c)
			cnt++;
		i++;
	}
	return (cnt);
}

void	ft_settemp(char **buffer, char *line, int fr)
{
	char	*aux;

	aux = NULL;
	if (fr == 1)
		*buffer = ft_strdup(line);
	else if (fr > 1)
	{
		aux = ft_strjoin(*buffer, line);
		free(*buffer);
		*buffer = ft_strdup(aux);
		free(aux);
		aux = NULL;
	}
}
