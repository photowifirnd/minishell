#include "../includes/minishell.h"

int	ft_pwd()
{
	char	cwd[256];
	printf("%s\n", getcwd(cwd, 256));
	return (1);
}
