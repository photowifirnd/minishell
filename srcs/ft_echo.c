#include "../includes/minishell.h"

int ft_echo(char *line, t_command *cmd)
{
    int i;
    int j;

    cmd->args = ft_split(&line[cmd->i], ' ');
    i = 0;
    cmd->echo_flag = 0;
    if (!(ft_strcmp(cmd->args[0], "-n")))
    {
        cmd->echo_flag = 1;
        i++;
        free(cmd->args[0]);
    }
    while(cmd->args[i] != NULL)
    {
        j = 0;
        while(cmd->args[i][j] != '\0')
        {
            write(1, &cmd->args[i][j], 1);
            j++;
        }
        free(cmd->args[i]);
        i++;
        if (cmd->args[i] != NULL)
            write(1, " ", 1);
    }
    free(cmd->args);
    if (!cmd->echo_flag)
        write(1, "\n", 1);
    return (0);
}
