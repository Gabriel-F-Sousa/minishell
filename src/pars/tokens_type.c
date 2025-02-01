#include "../minishell.h"

t_token_type define_type(t_token *token, t_token *prev_token)
{
	size_t len;

	if (!token || !token->str || token->str[0] == '\0')
		return EOI;
	if (strcmp(token->str, "|") == 0)
		return PIPE;
	if (strcmp(token->str, ">") == 0)
		return TOKEN_REDIR_OUT;
	if (strcmp(token->str, "<") == 0)
		return TOKEN_REDIR_IN;
	if (strcmp(token->str, "<<") == 0)
		return TOKEN_HEREDOC;
	if (strcmp(token->str, ">>") == 0)
		return TOKEN_APPEND;
	if (strcmp(token->str, ";") == 0)
		return SEP;
	if (token->str[0] == '$')
	{
		if (strcmp(token->str, "$?") == 0)
			return STATUS_VAR;
		return ENV_VAR;
	}

	len = strlen(token->str);
	if ((token->str[0] == '"' && token->str[len - 1] == '"') ||
		(token->str[0] == '\'' && token->str[len - 1] == '\''))
		return STR;

	if (prev_token && (prev_token->type == CMD || prev_token->type == ARG ||
					   prev_token->type == TOKEN_REDIR_IN ||
					   prev_token->type == TOKEN_REDIR_OUT ||
					   prev_token->type == TOKEN_HEREDOC ||
					   prev_token->type == TOKEN_APPEND))
		return ARG;

	return CMD;
}

/*
int main()
{
	printf("Type of |: %d\n", define_type("|"));//PIPE
	printf("Type of ls: %d\n", define_type("ls"));//CMD
	printf("Type of $HOME: %d\n", define_type("$HOME"));//ENV_VAR
	printf("Type of $? : %d\n", define_type("$?"));//STATUS_VAR
	printf("Type of cd: %d\n", define_type("cd"));//BUILTIN
	printf("Type of 'text': %d\n", define_type("'text'"));//STR
	return 0;
}*/
