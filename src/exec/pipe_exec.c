#include "../minishell.h"

void	debug_print_command(t_token *start, char **args)
{
	int	i;

	ft_printf("Executing command: %s\n", start->str);
	ft_printf("Arguments:\n");
	i = 0;
	while (args[i])
	{
		ft_printf("  arg[%d]: %s\n", i, args[i]);
		i++;
	}
}

int	setup_child_pipes(int pipe_in, int pipe_out)
{
	if (pipe_in != -1)
	{
		dup2(pipe_in, STDIN_FILENO);
		close(pipe_in);
	}
	if (pipe_out != -1)
	{
		dup2(pipe_out, STDOUT_FILENO);
		close(pipe_out);
	}
	return (0);
}

void	close_parent_pipes(int pipe_in, int pipe_out)
{
	if (pipe_in != -1)
		close(pipe_in);
	if (pipe_out != -1)
		close(pipe_out);
}

int	execute_piped_command(t_token *start, int pipe_in, int pipe_out)
{
	pid_t	pid;
	int		status;
	char	**args;
	char	*cmd_path;

	pid = fork();
	if (pid == 0)
	{
		if (pipe_in != -1)
		{
			if (dup2(pipe_in, STDIN_FILENO) == -1)
				exit(1);
			close(pipe_in);
		}
		if (pipe_out != -1)
		{
			if (dup2(pipe_out, STDOUT_FILENO) == -1)
				exit(1);
			close(pipe_out);
		}
		args = create_command_args(start);
		if (!args)
			exit(1);
		cmd_path = find_command(args[0]);
		if (cmd_path)
		{
			execve(cmd_path, args, NULL);
			free(cmd_path);
		}
		free_args(args);
		exit(1);
	}
	else if (pid < 0)
		return (1);
	close_parent_pipes(pipe_in, pipe_out);
	waitpid(pid, &status, 0);
	return (WEXITSTATUS(status));
}
