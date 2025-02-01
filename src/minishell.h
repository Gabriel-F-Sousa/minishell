#ifndef MINISHELL_H
# define MINISHELL_H

// #define TOKEN_CMD		1
// #define TOKEN_ARG		2
// #define TOKEN_REDIR_IN	3    // 
// #define TOKEN_REDIR_OUT	4    // >
// #define TOKEN_HEREDOC	5    // 
// #define TOKEN_APPEND	6    // >>

# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

#define PROMPT "minishell> "

#define C		"\033[1;36m"
#define RED		"\033[1;31m"
#define RST		"\033[0m"

#define p(...) printf(__VA_ARGS__)

typedef	enum e_token_type
{
	CMD = 1,
	ARG,
	PIPE,
	REDIR,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_HEREDOC,
	TOKEN_APPEND,
	REDIR_FD,
	ENV_VAR,
	STATUS_VAR,
	STR,
	SEP,
	EOI
}	t_token_type;


typedef struct s_token
{
	char	*str;
	int	type;
	struct s_token *next;
	struct s_token *prev;
	int fd_in;
	int fd_out;
}	t_token;

typedef struct s_shell
{

}	t_shell;

// typedef struct s_token
// {
// 	char *str;
// 	int tipo;
// 	struct s_token *prev;
// 	struct s_token *next;
// 	int fd_in;     // For input redirection
// 	int fd_out;    // For output redirection
// } t_token;


int		execute_from_list(t_token *head);
char	*find_command(char *cmd);
void	free_args(char **args);

// redirections.c
int handle_redirections(t_token *head);
int handle_input_redirection(char *file);
int handle_output_redirection(char *file, int append);
int handle_heredoc(char *delimiter);

// parsing
void	Getcwd(char *buf, size_t size);

int yesspace(char c);
char *norm_prompt(char *prompt);
int if_special(char c);
int	skip_space(const char *input, int i);
int	skip_token_end(const char *input, int i);
t_token	*create_token(const char *input, int start, int end, t_token *prev);
t_token	*tokenize(char *input);
t_token_type define_type(t_token *token, t_token *prev_token);
char	*cell_read_line(void);
#endif