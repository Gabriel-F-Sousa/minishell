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
	if (current && current->type == PIPE)
		return (current);
	return (current);
}

t_token	*get_next_command_after_pipe(t_token *current)
{
	current = current->next;
	while (current && current->type != CMD)
	{
		if (current->type == PIPE)
			return (NULL);
		current = current->next;
	}
	return (current);
}

t_token	*get_next_command(t_token *current)
{
	if (!current || !current->next)
		return (NULL);
	if (current->type != PIPE)
	{
		while (current && current->type != PIPE)
			current = current->next;
		if (!current || !current->next)
			return (NULL);
	}
	return (get_next_command_after_pipe(current));
}
