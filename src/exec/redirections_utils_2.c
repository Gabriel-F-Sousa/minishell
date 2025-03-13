#include "../minishell.h"

int	process_redirection(t_token *current, t_token **cmd, int *fd, int type)
{
	if (type == TOKEN_REDIR_IN)
		*fd = handle_input_redirection(current->next->str);
	else if (type == TOKEN_REDIR_OUT)
		*fd = handle_output_redirection(current->next->str, 0);
	else if (type == TOKEN_HEREDOC)
		*fd = handle_heredoc(current->next->str);
	else if (type == TOKEN_APPEND)
		*fd = handle_output_redirection(current->next->str, 1);
	if (*fd < 0)
		return (1);
	*cmd = find_redirection_command(current);
	apply_redirection(*cmd, *fd, is_input_redirection(type));
	return (0);
}

int	handle_redirections(t_token *head)
{
	t_token	*current;
	t_token	*cmd;
	int		fd;

	current = head;
	while (current)
	{
		if (is_redirection_token(current->type) && current->next)
		{
			if (process_redirection(current, &cmd, &fd, current->type))
				return (1);
		}
		current = current->next;
	}
	return (0);
}
