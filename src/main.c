#include "minishell.h"



void free_tokens(t_token *head)
{
	t_token	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->str);
		free(temp);
	}
}

char	*check_direct_path(char *cmd)
{
	char	*path;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
		{
			path = ft_strdup(cmd);
			return (path);
		}
	}
	return (NULL);
}

char	*get_path_var(void)
{
	char *path;
	
	path = getenv("PATH");
	if (!path)
		return (NULL);
	return (ft_strdup(path));
}

char *create_full_path(char *dir, char *cmd)
{
	char *temp;
	char *full_path;
	
	temp = ft_strjoin(dir, "/");
	if (!temp)
		return (NULL);
	full_path = ft_strjoin(temp, cmd);
	free(temp);
	return (full_path);
}

char	*find_command(char *cmd)
{
	char	*path;
	char	*path_copy;
	char	*dir;
	char	*full_path;

	path = check_direct_path(cmd);
	if (path)
		return (path);
	path = get_path_var();
	if (!path)
		return (NULL);
	path_copy = path;
	while ((dir = ft_strsep(&path_copy, ":")))
	{
		full_path = create_full_path(dir, cmd);
		if (!full_path)
		{
			free(path);
			return (NULL);
		}
		if (access(full_path, X_OK) == 0)
		{
			free(path);
			return (full_path);
		}
		free(full_path);
	}
	free(path);
	return (NULL);
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


int main()
{
	char *line;
	t_token *token;
	// line = cell_read_line();
	// token = tokenize(line);
	while ((line = cell_read_line())){
		token = tokenize(line);
		// printf("%s", token->str);
		execute_from_list(token);
		// printf("%s\n", line);
	}
}




// int	main(int argc, char **argv)
// {
// 	char	**args;
// 	t_token	*head;
// 	t_token	*new;
// 	int		i;

// 	i = 0;
// 	head = NULL;
// 	if (argc < 2)
// 		return (1);
// 	args = ft_split(argv[1], ' ');
// 	if (!args)
// 		return (1);
// 	while (args[i] != NULL)
// 	{
// 		new = create_new_token(args[i]);
// 		if (!new)
// 			return (1);
// 		add_token_back(&head, new);
// 		i++;
// 	}
// 	free_args(args);
// 	if (head && head->type == 1)
// 		execute_from_list(head);
// 	free_tokens(head);
// 	return (0);
// }


