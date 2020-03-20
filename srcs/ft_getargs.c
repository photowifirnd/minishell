#include "../includes/minishell.h"

char	*ft_parse_cmd(char *cmd, t_command *cmd_index)
{
	unsigned int	i;
	unsigned int	start;
	size_t		len;
	char		*tmp;

	i = 0;
	len = 0;
	while (cmd[i] == ' ' && cmd[i] != '\0')
		i++;
	start = i;
	while (cmd[i] != ' ' && cmd[i] != '\0')
	{
		len++;
		i++;
	}
	tmp = ft_strsub(cmd, start, len); //Ojo, al llamar a ft_strsub se hace un malloc que debe ser liberado. Si hay un error devolvera un NULL que se podrá liberar. No debe liberarse aquí. Seguir la funcion que llama para liberar
	
	cmd_index->i = i;

	return (tmp);	
}

void	ft_get_args(char *line, t_command *cmd)
{
	static size_t	first_read = 0;
	char		*buffer;
	char		*aux;
	size_t		cnt;

	first_read++;
	if (ft_strlen(line) && (cnt = ft_get_quotes(line, '"')) > 0)
	{
	buffer = NULL;
	ft_settemp(&buffer, line, first_read);
	if ((cnt = ft_get_quotes(buffer, '"')))
	{
		first_read++;
		while (cnt % 2)
		{
			free(line);
			line = NULL;
			ft_gnl(0, &line);
			ft_settemp(&buffer, line, first_read);
			cnt = ft_get_quotes(buffer, '"');
		}
	}
	if (!line)
		line = buffer;
	else
	{
		free(line);
		line = ft_strdup(buffer);
		free(buffer);
		buffer = NULL;
	}
	}
	first_read = 0;
	cmd->command = ft_parse_cmd(line, cmd); 
}
