
#include "../minishell.h"

int	count_piped_commands(t_token *head)
{
	t_token	*current;
	int		count;

	current = head;
	count = 1;
	while (current)
	{
		if (current->type == PIPE)
			count++;
		current = current->next;
	}
	return (count);
}

t_token	*find_command_end(t_token *start)
{
	t_token	*current;

	current = start;
	while (current && current->type != PIPE)
		current = current->next;
	if (current)
		return (current->prev);
	return (current);
}

void	setup_pipes(int *pipe_fd, int *prev_pipe, int is_last)
{
	if (!is_last)
	{
		if (pipe(pipe_fd) < 0)
			ft_printf("Pipe creation failed\n");
	}
	if (*prev_pipe != -1)
	{
		dup2(*prev_pipe, STDIN_FILENO);
		close(*prev_pipe);
	}
}

void	cleanup_pipes(int *pipe_fd, int *prev_pipe, int is_last)
{
	if (!is_last)
	{
		if (pipe_fd[1] != -1)
			close(pipe_fd[1]);
		*prev_pipe = pipe_fd[0];
	}
	if (*prev_pipe != -1)
		close(*prev_pipe);
}
