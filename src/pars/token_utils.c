#include "../minishell.h"

void	free_tokens(t_token *head)
{
	t_token	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		if (temp->fd_in != -1)
			close(temp->fd_in);
		if (temp->fd_out != -1)
			close(temp->fd_out);
		free(temp->str);
		free(temp);
	}
}

t_token	*create_new_token(char *str)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->str = ft_strdup(str);
	if (!new->str)
	{
		free(new);
		return (NULL);
	}
	new->type = 1;
	new->prev = NULL;
	new->next = NULL;
	new->fd_in = -1;
	new->fd_out = -1;
	return (new);
}

void	add_token_back(t_token **head, t_token *new)
{
	t_token	*last;

	if (!*head)
	{
		*head = new;
		return ;
	}
	last = *head;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}