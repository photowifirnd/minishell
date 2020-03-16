#include "../includes/minishell.h"

void	init_shell(t_env *env)
{
	int	status;
	char	*line;
	//char	*args;
	t_command	cmd;

	status = 1;
	while (status)
	{
		write(1, env->pwd, ft_strlen(env->pwd));
		write(1, "$>", 2);
		ft_gnl(&line);
		ft_get_args(line, &cmd);
		status = ft_exec_command(&cmd, line);
		free (line);
	}
}

int	main(int args, char **argsv)
{
	(void)args;
	(void)argsv;
	t_env		env;

	ft_setpwd(&env);
	init_shell(&env);
	free (env.pwd);
	write(1, "\n\n", 2);
	system("leaks minishell");
	return (0);
}
