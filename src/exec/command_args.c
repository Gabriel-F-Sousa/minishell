#include "../minishell.h"

int	should_add_arg(t_token *temp)
{
	if (!temp)
		return (0);
	if ((temp->type == CMD || temp->type == ARG || temp->type == STR)
		&& !is_redirection_arg(temp))
		return (1);
	return (0);
}

int	add_arg_to_array(char **args, t_token *temp, int i)
{
	args[i] = ft_strdup(temp->str);
	if (!args[i])
	{
		free_args_alloc(args, i);
		return (-1);
	}
	return (0);
}

char	**create_command_args(t_token *start)
{
	char	**args;
	t_token	*temp;
	int		i;
	int		arg_count;

	arg_count = count_command_args(start);
	args = create_args_alloc(arg_count);
	if (!args)
		return (NULL);
	temp = start;
	i = 0;
	while (temp && temp->type != PIPE && i < arg_count)
	{
		if (should_add_arg(temp))
		{
			if (add_arg_to_array(args, temp, i) == -1)
				return (NULL);
			i++;
		}
		temp = temp->next;
	}
	args[i] = NULL;
	return (args);
}
