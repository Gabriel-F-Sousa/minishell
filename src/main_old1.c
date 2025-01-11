
#include "minishell.h"

int	main(int argc, char **argv)
{
	char	**args;
	// t_token	*head;
	// t_token	*new;
	int		i;

	if (argc < 2)
		return (1);
	i = 0;
	args = ft_split(argv[1], ' ');
	while (args[i] != '\0')
	{
		printf("%s", args[i]);
		i++;
	}

}