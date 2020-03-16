#include "../includes/minishell.h"

void	ft_get_args(char *line, char **args)
{
	int i;

	i = 0;
	*args = (char *)malloc(sizeof(char *) * 1);
	args[0] = (char *)malloc(ft_strlen(line) + 1);
	while (*line)
		args[0][i++] = *line++;
	args[0][i] = '\0';
	printf("Esto es lo que pediste: %s\n", args[0]);
}
