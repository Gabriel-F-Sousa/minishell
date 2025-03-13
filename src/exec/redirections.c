#include "../minishell.h"

t_token	*find_redirection_command(t_token *redir)
{
	t_token	*cmd;

	cmd = redir;
	while (cmd && cmd->type != CMD && cmd->type != PIPE)
		cmd = cmd->prev;
	if (!cmd || cmd->type == PIPE)
	{
		cmd = redir;
		while (cmd && cmd->type != CMD && cmd->type != PIPE)
			cmd = cmd->next;
		if (!cmd || cmd->type == PIPE)
			return (NULL);
	}
	return (cmd);
}

int	handle_input_redirection(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("minishell: %s: No such file or directory\n", file);
		return (-1);
	}
	return (fd);
}

int	handle_output_redirection(char *file, int append)
{
	int	fd;
	int	flags;

	flags = O_WRONLY | O_CREAT;
	if (append)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	fd = open(file, flags, 0644);
	if (fd < 0)
	{
		ft_printf("minishell: %s: Permission denied\n", file);
		return (-1);
	}
	return (fd);
}

int	handle_heredoc_input(char *delimiter, int pipe_fd[2])
{
	char	*line;

	ft_printf("heredoc> ");
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter) + 1) == 0)
		{
			free(line);
			break ;
		}
		write(pipe_fd[1], line, ft_strlen(line));
		write(pipe_fd[1], "\n", 1);
		free(line);
		ft_printf("heredoc> ");
	}
	return (0);
}
