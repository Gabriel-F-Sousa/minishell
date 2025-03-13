/* src/main.c */
#include "minishell.h"

int	main(void)
{
	char	*line;
	t_token	*token;

	while (1)
	{
		line = cell_read_line();
		if (!line)
		{
			ft_printf("\n");
			break ;
		}
		if (line[0] == '\n' || line[0] == '\0')
		{
			free(line);
			continue ;
		}
		token = tokenize(line);
		if (!token)
		{
			free(line);
			continue ;
		}
		process_all_tokens(token);
		if (handle_redirections(token) == 0)
			execute_from_list(token);
		free_tokens(token);
		free(line);
	}
	return (0);
}