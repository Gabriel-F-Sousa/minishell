#include "../minishell.h"

int	handle_heredoc(char *delimiter)
{
	int	pipe_fd[2];

	if (pipe(pipe_fd) < 0)
		return (-1);
	handle_heredoc_input(delimiter, pipe_fd);
	close(pipe_fd[1]);
	return (pipe_fd[0]);
}

void	apply_redirection(t_token *cmd, int fd, int is_input)
{
	if (!cmd)
		return ;
	if (is_input && cmd->fd_in != -1)
		close(cmd->fd_in);
	else if (!is_input && cmd->fd_out != -1)
		close(cmd->fd_out);
	if (is_input)
		cmd->fd_in = fd;
	else
		cmd->fd_out = fd;
}

int	is_input_redirection(int type)
{
	return (type == TOKEN_REDIR_IN || type == TOKEN_HEREDOC);
}

int	is_redirection_token(int type)
{
	return (type == TOKEN_REDIR_IN || type == TOKEN_REDIR_OUT
		|| type == TOKEN_HEREDOC || type == TOKEN_APPEND);
}
