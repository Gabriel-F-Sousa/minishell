#include "../minishell.h"

// Function to get the value of an environment variable
char *get_env_value(char *var_name)
{
	char *value;
	
	if (!var_name || !*var_name)
		return ft_strdup("");
	
	// Handle $? for exit status
	if (ft_strncmp(var_name, "?", 2) == 0)
	{
		// You'll need to track the exit status of the last command
		// For now, we'll return "0" as a placeholder
		return ft_strdup("0");
	}
	
	value = getenv(var_name);
	if (!value)
		return ft_strdup("");
	
	return ft_strdup(value);
}

// Function to expand environment variables in a string
char *expand_variables(char *str)
{
	char *result = NULL;
	char *temp = NULL;
	char *var_name = NULL;
	char *var_value = NULL;
	int i = 0;
	int start = 0;
	
	if (!str)
		return NULL;
	
	result = ft_strdup("");
	if (!result)
		return NULL;
	
	while (str[i])
	{
		// Find $ character
		if (str[i] == '$' && str[i + 1] && (ft_isalnum(str[i + 1]) || str[i + 1] == '?' || str[i + 1] == '_'))
		{
			// Append everything before the $
			if (i > start)
			{
				char *before = ft_substr(str, start, i - start);
				if (!before)
				{
					free(result);
					return NULL;
				}
				
				temp = ft_strjoin(result, before);
				free(before);
				free(result);
				result = temp;
			}
			
			// Extract variable name
			int var_start = i + 1;
			int var_end = var_start;
			
			if (str[var_end] == '?')
				var_end++;
			else
				while (str[var_end] && (ft_isalnum(str[var_end]) || str[var_end] == '_'))
					var_end++;
			
			var_name = ft_substr(str, var_start, var_end - var_start);
			if (!var_name)
			{
				free(result);
				return NULL;
			}
			
			// Get variable value
			var_value = get_env_value(var_name);
			free(var_name);
			
			// Append variable value to result
			temp = ft_strjoin(result, var_value);
			free(var_value);
			free(result);
			result = temp;
			
			// Update position
			i = var_end;
			start = var_end;
		}
		else
			i++;
	}
	
	// Append any remaining part of the string
	if (str[start])
	{
		temp = ft_strjoin(result, str + start);
		free(result);
		result = temp;
	}
	
	return result;
}

// Function to remove backslashes from a string
char *remove_backslashes(char *str)
{
	char *result;
	int i, j;
	int len;
	
	if (!str)
		return NULL;
	
	len = ft_strlen(str);
	result = malloc(len + 1);
	if (!result)
		return NULL;
	
	i = 0;
	j = 0;
	
	while (i < len)
	{
		// If we find a backslash, skip it and copy the next character
		if (str[i] == '\\' && i + 1 < len)
		{
			result[j++] = str[i + 1];
			i += 2;
		}
		else
		{
			result[j++] = str[i++];
		}
	}
	
	result[j] = '\0';
	return result;
}

void process_token_quotes(t_token *token)
{
	int len;
	char *content;
	char *expanded;
	char *processed;
	
	if (!token || !token->str)
		return;
	
	len = ft_strlen(token->str);
	
	// Single quote - preserve content literally
	if (len >= 2 && token->str[0] == '\'' && token->str[len - 1] == '\'')
	{
		// Extract content between quotes
		content = ft_substr(token->str, 1, len - 2);
		if (!content)
			return;
		
		// Replace token string with content
		free(token->str);
		token->str = content;
	}
	// Double quote - expand variables
	else if (len >= 2 && token->str[0] == '"' && token->str[len - 1] == '"')
	{
		// Extract content between quotes
		content = ft_substr(token->str, 1, len - 2);
		if (!content)
			return;
		
		// Expand variables in content
		expanded = expand_variables(content);
		free(content);
		
		if (!expanded)
			return;
		
		// Replace token string with expanded content
		free(token->str);
		token->str = expanded;
	}
	// Process backslashes in non-quoted tokens
	else
	{
		int has_backslash = 0;
		for (int i = 0; token->str[i]; i++)
		{
			if (token->str[i] == '\\')
			{
				has_backslash = 1;
				break;
			}
		}
		
		if (has_backslash)
		{
			processed = remove_backslashes(token->str);
			if (processed)
			{
				free(token->str);
				token->str = processed;
			}
		}
	}
}

void process_all_tokens(t_token *head)
{
	t_token *current = head;
	
	while (current)
	{
		process_token_quotes(current);
		current = current->next;
	}
}