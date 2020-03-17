#include "../includes/minishell.h"

int	ft_exec_command(t_command *cmd)
{
	if (!cmd->command)
		return (1);
	if (!ft_strcmp(cmd->command, "exit"))
		return (ft_exit(cmd));
	else if (!ft_strcmp(cmd->command, "pwd"))
		return (ft_pwd());
	return (1);
}
