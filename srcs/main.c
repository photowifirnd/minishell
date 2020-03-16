#include "../includes/minishell.h"

void	init_shell()
{
	int	status;
	char	*line;
	char	*args;
	t_command	cmd;

	status = 1;
	while (status)
	{
		write(1, "$>", 2);
		ft_gnl(&line);
		ft_get_args(line, &cmd);
//		status = ft_exec_command(args);		
	}
}

int	main(int args, char **argsv)
{
	(void)args;
	(void)argsv;
	init_shell();
	return (0);
}
