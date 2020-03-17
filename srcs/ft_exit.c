#include "../includes/minishell.h"

int	ft_exit(t_command *cmd)
{
	if (!cmd->command)
		return (1);
//	free (cmd->command);
	return (0);
}
