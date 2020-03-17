#include "../includes/minishell.h"

int	ft_pwd()
{
	char	cwd[256];

	getcwd(cwd, 256);
	write (1, cwd, ft_strlen(cwd));
	write (1, "\n", 1);
	return (1);
}
