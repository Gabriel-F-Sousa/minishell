#include "../minishell.h"

int yesspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\f' || c == '\r');
}

int if_special(char c)
{
	return (c == '|' || c == '<' || c == '>' || c == '&' || c == ';');
}

char *norm_prompt(char *prompt) //facil de entender
{
	int len;
	int j;
	int i;
	char *result;
	len = ft_strlen(prompt);
	result = malloc(len * 5);
	if (!result)
		// Error Malloc
	j = 0;
	i = -1;
	while(++i < len)
	{
		if (if_special(prompt[i]))
		{
			if (i > 0 && !yesspace(result[j - 1]))
				result[j++] = ' ';
			result[j++] = prompt[i];
			if (i < len - 1 && !yesspace(prompt[i + 1]))
				result[j++] = ' ';
		}
		else
		{
			result[j++] = prompt[i];
		}
	}
	result[j] = '\0';
	return (result);
}

