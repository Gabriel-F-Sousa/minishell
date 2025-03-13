#include "../minishell.h"

int	is_redirection_arg(t_token *temp)
{
	if (!temp || !temp->prev)
		return (0);
	if (temp->prev->type == TOKEN_REDIR_IN)
		return (1);
	if (temp->prev->type == TOKEN_REDIR_OUT)
		return (1);
	if (temp->prev->type == TOKEN_HEREDOC)
		return (1);
	if (temp->prev->type == TOKEN_APPEND)
		return (1);
	return (0);
}

int	count_command_args(t_token *start)
{
	t_token	*temp;
	int		arg_count;

	temp = start;
	arg_count = 0;
	while (temp && temp->type != PIPE)
	{
		if (temp->type == CMD || temp->type == ARG || temp->type == STR)
		{
			if (is_redirection_arg(temp))
			{
				temp = temp->next;
				continue ;
			}
			arg_count++;
		}
		temp = temp->next;
	}
	return (arg_count);
}

char	**create_args_alloc(int arg_count)
{
	char	**args;

	if (arg_count == 0)
		return (NULL);
	args = malloc(sizeof(char *) * (arg_count + 1));
	if (!args)
		return (NULL);
	return (args);
}

void	free_args_alloc(char **args, int i)
{
	while (--i >= 0)
		free(args[i]);
	free(args);
}
