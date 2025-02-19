#include "../minishell.h"

t_token	*get_next_command(t_token *current)
{
	if (!current || !current->next)
		return (NULL);
	return (current->next->next);
}

void	handle_command(t_token *cmd, int *pip_fd, int *p_prev, int last)
{
	int	p_out;

	if (!last)
	{
		if (pipe(pip_fd) == -1)
		{
			ft_printf("Pipe creation failed\n");
			return ;
		}
		p_out = pip_fd[1];
	}
	else
		p_out = -1;
	execute_piped_command(cmd, *p_prev, p_out);
	if (!last)
	{
		close(pip_fd[1]);
		if (*p_prev != -1)
			close(*p_prev);
		*p_prev = pip_fd[0];
	}
}

int	count_command_args(t_token *start)
{
	t_token	*temp;
	int		arg_count;

	temp = start;
	arg_count = 0;
	while (temp && temp->type != PIPE)
	{
		if (temp->type != TOKEN_REDIR_IN && temp->type != TOKEN_REDIR_OUT
			&& temp->type != TOKEN_HEREDOC && temp->type != TOKEN_APPEND)
			arg_count++;
		temp = temp->next;
	}
	return (arg_count);
}

char	**create_command_args(t_token *start)
{
	char	**args;
	t_token	*temp;
	int		i;
	int		arg_count;

	arg_count = count_command_args(start);
	args = malloc(sizeof(char *) * (arg_count + 1));
	if (!args)
		return (NULL);
	temp = start;
	i = 0;
	while (temp && temp->type != PIPE)
	{
		if (temp->type != TOKEN_REDIR_IN && temp->type != TOKEN_REDIR_OUT 
			&& temp->type != TOKEN_HEREDOC && temp->type != TOKEN_APPEND)
		{
			args[i] = ft_strdup(temp->str);
			i++;
		}
		temp = temp->next;
	}
	args[i] = NULL;
	return (args);
}
