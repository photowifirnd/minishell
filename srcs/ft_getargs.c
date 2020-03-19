#include "../includes/minishell.h"

char	*ft_parse_cmd(char *cmd, t_command *cmd_index)
{
	unsigned int	i;
	unsigned int	start;
	size_t		len;
	//int		flag;
	char		*tmp;
	//char		quote;

	i = 0;
	len = 0;
	//quote = 0;
	while (cmd[i] == ' ' && cmd[i] != '\0')
		i++;
/*	if (cmd[i] == '"')
	{
		flag = 1;
		i++;
	}*/
	start = i;
	/*while (flag == 1 && cmd[i] != '\0')
	{
		if (cmd[i] == '"')
			flag = 0;
		i++;
		len++;
	}*/
	while (cmd[i] != ' ' && cmd[i] != '\0')
	{
		len++;
		i++;
	}
	/*if (flag)
	{
		read(0, &quote, 1);
		len++;
	}*/
	tmp = ft_strsub(cmd, start, len); //Ojo, al llamar a ft_strsub se hace un malloc que debe ser liberado. Si hay un error devolvera un NULL que se podrá liberar. No debe liberarse aquí. Seguir la funcion que llama para liberar
	
	cmd_index->i = i;

	return (tmp);	
}

void	ft_get_args(char *line, t_command *cmd)
{
	int i;

	i = 0;
	cmd->command = ft_parse_cmd(line, cmd); //Esta función devuelve un char * del que se ha reservado memoria con malloc. debe ser liberado cundo ya no haga falta.
//	args[0] = (char *)malloc(ft_strlen(line) + 1);
//	while (*line)
//		args[0][i++] = *line++;
//	args[0][i] = '\0';
	//printf("El comando es: %s\n", cmd->command);
}
