#include "../minishell.h"

void	Getcwd(char *buf, size_t size)
{
	if (NULL == getcwd(buf, size))
		perror(RED"getcwd FAILED"RST);
}

char	*cell_read_line(void)
{
	char	*buf;
	size_t	bufsize;
	char	cwd[50];

	buf = NULL;
	bufsize = 0;
	Getcwd(cwd, sizeof(cwd));
	ft_printf(C" %s "RST"$> ", cwd);
	
	if (getline(&buf, &bufsize, stdin) == -1)
	{
		free(buf);  // Free buf if getline fails
		if (feof(stdin))
			return (NULL);  // Return NULL on EOF
		ft_printf(RED"Getline failed"RST);
		return (NULL);
	}
	return (buf);
}


void	print_tokens(t_token *tokens)
{
	t_token *current = tokens;

	while (current)
	{
		printf("Token: %s, Type: %d", current->str, current->type);
		if (current->next)
			printf(" (Next-> %s)", current->next->str);
		else
			printf(" (Next-> NULL)");
		if (current->prev)
			printf(" (Prev-> %s)", current->prev->str);
		else
			printf(" (Prev-> NULL)");
		printf("\n");
		current = current->next;
	}
}

// int main(int ac, char **av)
// {
// 	char	*line;

// 	while ((line = cell_read_line()))
// 	{
// 		p("%s\n", line);
// 	}
// 	return (0);
// }
