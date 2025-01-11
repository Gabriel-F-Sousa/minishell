#ifndef MINISHELL_H
# define MINISHELL_H

#define TOKEN_CMD		1
#define TOKEN_ARG		2
#define TOKEN_REDIR_IN	3    // 
#define TOKEN_REDIR_OUT	4    // >
#define TOKEN_HEREDOC	5    // 
#define TOKEN_APPEND	6    // >>

# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

typedef struct s_token
{
	char *str;
	int tipo;
	struct s_token *prev;
	struct s_token *next;
	int fd_in;     // For input redirection
	int fd_out;    // For output redirection
} t_token;


int		execute_from_list(t_token *head);
char	*find_command(char *cmd);
void	free_args(char **args);

// redirections.c
int handle_redirections(t_token *head);
int handle_input_redirection(char *file);
int handle_output_redirection(char *file, int append);
int handle_heredoc(char *delimiter);

#endif