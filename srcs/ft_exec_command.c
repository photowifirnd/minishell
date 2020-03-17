#include "../includes/minishell.h"

int	ft_exec_command(t_command *cmd)
{
	int ret;
	
	ret = 1;
	if (!cmd->command)
		return (ret);
	if (!ft_strcmp(cmd->command, "exit"))
		ret = (ft_exit(cmd));
	else if (!ft_strcmp(cmd->command, "pwd"))
		ret = (ft_pwd());
	free (cmd->command);
	return (ret);
}
