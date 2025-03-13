#include "../minishell.h"

void	setup_pipe(t_token *cmd, int *pipe_fd)
{
	if (pipe(pipe_fd) == -1)
	{
		ft_printf("minishell: pipe creation failed\n");
		return ;
	}
	if (cmd->fd_out == -1)
		cmd->fd_out = pipe_fd[1];
	else
		close(pipe_fd[1]);
}

void	handle_pipe_cleanup(int *prev_pipe, int pipe_fd[2], int is_last)
{
	if (*prev_pipe != -1)
		close(*prev_pipe);
	if (!is_last)
		*prev_pipe = pipe_fd[0];
	else
		*prev_pipe = -1;
}

void	handle_command(t_token *cmd, int *pipe_fd, int *prev_pipe, int is_last)
{
	if (!cmd)
		return ;
	if (!is_last)
		setup_pipe(cmd, pipe_fd);
	execute_piped_command(cmd, *prev_pipe, cmd->fd_out);
	handle_pipe_cleanup(prev_pipe, pipe_fd, is_last);
}
