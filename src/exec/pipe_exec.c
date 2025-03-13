#include "../minishell.h"

void	setup_command_fds(t_token *start, int pipe_in, int pipe_out)
{
	int	stdin_fd;
	int	stdout_fd;

	stdin_fd = pipe_in;
	if (start->fd_in != -1)
		stdin_fd = start->fd_in;
	stdout_fd = pipe_out;
	if (start->fd_out != -1)
		stdout_fd = start->fd_out;
	if (stdin_fd != -1)
	{
		if (dup2(stdin_fd, STDIN_FILENO) == -1)
			exit(1);
		close(stdin_fd);
	}
	if (stdout_fd != -1)
	{
		if (dup2(stdout_fd, STDOUT_FILENO) == -1)
			exit(1);
		close(stdout_fd);
	}
}

void	execute_command(t_token *start)
{
	char	**args;
	char	*cmd_path;

	args = create_command_args(start);
	if (!args || !args[0])
	{
		free_args(args);
		exit(1);
	}
	cmd_path = find_command(args[0]);
	if (cmd_path)
	{
		execve(cmd_path, args, NULL);
		free(cmd_path);
	}
	else
		ft_printf("minishell: %s: command not found\n", args[0]);
	free_args(args);
	exit(1);
}

void	close_command_fds(t_token *start, int pipe_in, int pipe_out)
{
	if (start->fd_in != -1)
		close(start->fd_in);
	if (start->fd_out != -1)
		close(start->fd_out);
	if (pipe_in != -1)
		close(pipe_in);
	if (pipe_out != -1)
		close(pipe_out);
}

int	execute_piped_command(t_token *start, int pipe_in, int pipe_out)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		setup_command_fds(start, pipe_in, pipe_out);
		execute_command(start);
	}
	else if (pid < 0)
	{
		ft_printf("minishell: fork failed\n");
		return (1);
	}
	close_command_fds(start, pipe_in, pipe_out);
	waitpid(pid, &status, 0);
	return (WEXITSTATUS(status));
}
