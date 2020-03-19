#include "../includes/minishell.h"

void	init_shell(t_env *env)
{
	int	status;
	char	*line;
	//char	*args;
	t_command	cmd;

	cmd.list = env->list;
	status = 1;
	while (status)
	{
		write(1, env->pwd, ft_strlen(env->pwd));
		write(1, "$>", 2);
		ft_gnl(0, &line);
		ft_get_args(line, &cmd);
		status = ft_exec_command(&cmd, NULL);
		free (line);
	}
}

int	main(int args, char **argsv)
{
	(void)args;
	(void)argsv;
	t_env		env;

	ft_setpwd(&env);
	if (ft_setenv(&env) < 0)
		printf("Error asignando variables de entorno\n");//establece las variables de entorno en listas enlazadas dinamicas.
	init_shell(&env);
	free (env.pwd);
	system("leaks minishell");
	return (0);
}
