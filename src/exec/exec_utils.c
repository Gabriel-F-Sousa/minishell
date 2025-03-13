#include "../minishell.h"

int	execute_from_list(t_token *head)
{
	t_token	*current;
	int		cmd_count;

	current = find_first_command(head);
	if (!current)
		return (1);
	cmd_count = count_piped_commands(head);
	return (execute_commands(current, cmd_count));
}
