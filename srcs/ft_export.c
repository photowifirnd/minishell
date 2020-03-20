#include "../includes/minishell.h"

char	*ft_strstr_forward(t_command *cmd, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (cmd->command[i] != line[i])
		{
			while (line[i] == ' ')
				i++;
			return (&line[i]);
		}
		i++;
	}
	return (NULL);
}

int	ft_export(t_command *cmd, char *line)
{
	int	i;

	cmd->args = ft_split(ft_strstr_forward(cmd, line), ' ');
	if (!cmd->args)
	{
		free(cmd->args);
		return (2);
	}
	i = 0;
	if (i > 1)
	{
		i = 0;
		while (cmd->args[i])
			free(cmd->args[i++]);
		free(cmd->args);
		return (3);
	}
	//Agregar validador de variable: si espacio entre el signo = . Si existe =...
	ft_lstadd_front(&cmd->list, ft_lstnew(cmd->args[0]));
	free(cmd->args[0]);
	free(cmd->args);
	return (1);
}
