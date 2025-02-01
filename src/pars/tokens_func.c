#include "../minishell.h"

int skip_space(const char *input, int i)
{
	while (input[i] && (input[i] == ' ' || input[i] == '\t'))
		i++;
	return (i);
}

int skip_token_end(const char *input, int i)
{
	char quote;

	if (!input[i])
		return i;
	if ((input[i] == '>' && input[i + 1] == '>') || (input[i] == '<' && input[i + 1] == '<'))
		return (i + 2);
	if (if_special(input[i]))
		return (i + 1);
	if (input[i] == '"' || input[i] == '\'')
	{
		quote = input[i++];
		while (input[i] && input[i] != quote)
			i++;
		if (input[i] == quote)
			i++;
		return (i);
	}
	while (input[i] && !yesspace(input[i]) && !if_special(input[i]))
		i++;
	return (i);
}

t_token *create_token(const char *input, int start, int end, t_token *prev)
{
	t_token *n_token;
	char *token_str;

	if (start >= end)
		return NULL;

	n_token = malloc(sizeof(t_token));
	if (!n_token)
		return NULL;

	token_str = strndup(input + start, end - start);
	if (!token_str)
	{
		free(n_token);
		return NULL;
	}

	n_token->str = token_str;
	n_token->type = define_type(n_token, prev);
	n_token->next = NULL;
	n_token->prev = prev;

	return n_token;
}

t_token *tokenize(char *input)
{
	t_token *head = NULL;
	t_token *current = NULL;
	int i = 0;

	while (input[i])
	{
		i = skip_space(input, i);
		int start = i;
		i = skip_token_end(input, i);
		if (i > start)
		{
			t_token *new_token = create_token(input, start, i, current);
			if (!new_token)
				return head;
			if (!head)
				head = new_token;
			if (current)
				current->next = new_token;
			current = new_token;
		}
		else
			i++;
	}
	return head;
}
