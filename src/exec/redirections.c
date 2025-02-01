

#include "../minishell.h"

int handle_input_redirection(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("minishell: %s: No such file or directory\n", file);
		return (-1);
	}
	return (fd);
}

int handle_output_redirection(char *file, int append)
{
	int fd;
	int flags;

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

int handle_heredoc(char *delimiter)
{
	int pipe_fd[2];
	char *line;

	if (pipe(pipe_fd) < 0)
		return (-1);

	while (1)
	{
		ft_printf("> ");
		line = get_next_line(0);
		if (!line)
			break;
		
		line[ft_strlen(line) - 1] = '\0';
		
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0)
		{
			free(line);
			break;
		}
		
		write(pipe_fd[1], line, ft_strlen(line));
		write(pipe_fd[1], "\n", 1);
		free(line);
	}
	
	close(pipe_fd[1]);
	return (pipe_fd[0]);
}

int handle_redirections(t_token *head)
{
	t_token *current;
	int fd;

	current = head;
	while (current)
	{
		if (current->type == TOKEN_REDIR_IN && current->next)
		{
			fd = handle_input_redirection(current->next->str);
			if (fd < 0)
				return (1);
			// current->fd_in = fd;
			head->fd_in = fd;
		}
		else if (current->type == TOKEN_REDIR_OUT && current->next)
		{
			fd = handle_output_redirection(current->next->str, 0);
			if (fd < 0)
				return (1);
			// current->fd_out = fd;
			head->fd_out = fd;
		}
		else if (current->type == TOKEN_HEREDOC && current->next)
		{
			fd = handle_heredoc(current->next->str);
			if (fd < 0)
				return (1);
			// current->fd_in = fd;
			head->fd_in = fd;
		}
		else if (current->type == TOKEN_APPEND && current->next)
		{
			fd = handle_output_redirection(current->next->str, 1);
			if (fd < 0)
				return (1);
			// current->fd_out = fd;
			head->fd_out = fd;
		}
		current = current->next;
	}
	return (0);
}