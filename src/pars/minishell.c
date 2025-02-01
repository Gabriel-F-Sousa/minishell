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

	Getcwd(cwd, sizeof(cwd));
	p(C" %s "RST"$>", cwd);
	if (getline(&buf, &bufsize, stdin) == -1)
	{
		buf = NULL;
		if (feof(stdin))
			p(RED"[EOF]"RST);
		else
			p(RED"Getline failed"RST);
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
