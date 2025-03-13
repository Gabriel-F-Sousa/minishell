#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

#define PROMPT "minishell> "

#define C        "\033[1;36m"
#define RED      "\033[1;31m"
#define RST      "\033[0m"

#define p(...) printf(__VA_ARGS__)

typedef enum e_token_type
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
} t_token_type;

typedef struct s_token
{
    char    *str;
    int     type;
    struct s_token *next;
    struct s_token *prev;
    int     fd_in;
    int     fd_out;
} t_token;

typedef struct s_shell
{
    int last_status;
} t_shell;

// exec.c
void            free_args(char **args);
int             count_args(t_token *head);
char            **create_args_array(t_token *head, int arg_count);
t_token         *find_first_command(t_token *head);
int             execute_commands(t_token *current, int cmd_count);

// exec_utils.c
int             execute_from_list(t_token *head);

// token_utils.c
void            free_tokens(t_token *head);
t_token         *create_new_token(char *str);
void            add_token_back(t_token **head, t_token *new);

// path_utils.c
char            *check_direct_path(char *cmd);
char            *get_path_var(void);
char            *create_full_path(char *dir, char *cmd);
char            *try_paths(char *path, char *cmd);
char            *find_command(char *cmd);

// pipe_utils.c
int             count_piped_commands(t_token *head);
t_token         *find_command_end(t_token *start);
t_token         *get_next_command_after_pipe(t_token *current);
t_token         *get_next_command(t_token *current);

// pipe_utils_2.c
void            setup_pipe(t_token *cmd, int *pipe_fd);
void            handle_pipe_cleanup(int *prev_pipe, int pipe_fd[2], int is_last);
void            handle_command(t_token *cmd, int *pipe_fd, int *prev_pipe, int is_last);

// pipe_exec.c
void            setup_command_fds(t_token *start, int pipe_in, int pipe_out);
void            execute_command(t_token *start);
void            close_command_fds(t_token *start, int pipe_in, int pipe_out);
int             execute_piped_command(t_token *start, int pipe_in, int pipe_out);

// command_utils.c
int             is_redirection_arg(t_token *temp);
int             count_command_args(t_token *start);
char            **create_args_alloc(int arg_count);
void            free_args_alloc(char **args, int i);

// command_args.c
int             should_add_arg(t_token *temp);
int             add_arg_to_array(char **args, t_token *temp, int i);
char            **create_command_args(t_token *start);

// redirections.c
t_token         *find_redirection_command(t_token *redir);
int             handle_input_redirection(char *file);
int             handle_output_redirection(char *file, int append);
int             handle_heredoc_input(char *delimiter, int pipe_fd[2]);

// redirections_utils.c
int             handle_heredoc(char *delimiter);
void            apply_redirection(t_token *cmd, int fd, int is_input);
int             is_input_redirection(int type);
int             is_redirection_token(int type);

// redirections_utils_2.c
int             process_redirection(t_token *current, t_token **cmd, int *fd, int type);
int             handle_redirections(t_token *head);

// Common functions
int             handle_redirections(t_token *head);

// Parsing functions
void            Getcwd(char *buf, size_t size);
int             yesspace(char c);
char            *norm_prompt(char *prompt);
int             if_special(char c);
int             skip_space(const char *input, int i);
int             skip_token_end(const char *input, int i);
t_token         *create_token(const char *input, int start, int end, t_token *prev);
t_token         *tokenize(char *input);
t_token_type    define_type(t_token *token, t_token *prev_token);
char            *cell_read_line(void);

// New functions for quote handling and variable expansion
int             is_quote(char c);
char            *extract_token_content(const char *input, int start, int end);
void            set_token_quote_type(t_token *token);
char            *get_env_value(char *var_name);
char            *expand_variables(char *str);
char            *remove_backslashes(char *str);
void            process_token_quotes(t_token *token);
void            process_all_tokens(t_token *head);

#endif