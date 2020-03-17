#include "../includes/minishell.h"

void	ft_setpwd(t_env *env)
{
	env->pwd = getcwd(env->pwd, 0);
}
