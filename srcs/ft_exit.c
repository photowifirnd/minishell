#include "../includes/minishell.h"

void	del(void *content)
{
	free(content);
}

int	ft_exit(t_command *cmd)
{
	t_list	*tmp;

	if (!cmd->command)
		return (1);
	while (cmd->list)
	{
		tmp = cmd->list->next;
		free(cmd->list->content);
		cmd->list = tmp;
	}
//	free (cmd->command);
	return (0);
}
