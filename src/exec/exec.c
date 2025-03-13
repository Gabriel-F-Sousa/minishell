#include "../minishell.h"

void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	count_args(t_token *head)
{
	t_token	*temp;
	int		arg_count;

	temp = head;
	arg_count = 0;
	while (temp != NULL)
	{
		arg_count++;
		temp = temp->next;
	}
	return (arg_count);
}

char	**create_args_array(t_token *head, int arg_count)
{
	char	**args;
	t_token	*temp;
	int		i;

	args = malloc(sizeof(char *) * (arg_count + 1));
	if (!args)
		return (NULL);
	temp = head;
	i = 0;
	while (temp != NULL)
	{
		args[i] = ft_strdup(temp->str);
		temp = temp->next;
		i++;
	}
	args[i] = NULL;
	return (args);
}

t_token	*find_first_command(t_token *head)
{
	t_token	*current;

	current = head;
	while (current && current->type != CMD)
		current = current->next;
	return (current);
}

int	execute_commands(t_token *current, int cmd_count)
{
	int		pipe_fd[2];
	int		prev_pipe;
	int		i;
	int		j;

	pipe_fd[0] = -1;
	pipe_fd[1] = -1;
	prev_pipe = -1;
	i = 0;
	while (current && i < cmd_count)
	{
		handle_command(current, pipe_fd, &prev_pipe, i == cmd_count - 1);
		current = get_next_command(find_command_end(current));
		i++;
	}
	j = 0;
	while (j < cmd_count)
	{
		wait(NULL);
		j++;
	}
	return (0);
}
