
#include "../minishell.h"

void	free_args(char **args)
{
	int i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int count_args(t_token *head)
{
	t_token *temp;
	int arg_count;

	temp = head;
	arg_count = 0;
	while (temp != NULL)
	{
		arg_count++;
		temp = temp->next;
	}
	return (arg_count);
}

char **create_args_array(t_token *head, int arg_count)
{
	char **args;
	t_token *temp;
	int i;

	args = malloc(sizeof(char *) * (arg_count + 1));
	if (!args)
		return (NULL);
	temp = head;
	i = 0;
	while (temp != NULL)
	{
		args[i] = ft_strdup(temp->str);
		temp = temp->next;
		i++;
	}
	args[i] = NULL;
	return (args);
}

int execute_command(char *cmd_path, char **args, t_token *head)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (head->fd_in != 0)
		{
			dup2(head->fd_in, STDIN_FILENO);
			close(head->fd_in);
		}
		if (head->fd_out != 1)
		{
			dup2(head->fd_out, STDOUT_FILENO);
			close(head->fd_out);
		}
		execve(cmd_path, args, 0);
		free(cmd_path);
		free_args(args);
		return (1);
	}
	if (head->fd_in != 0)
		close(head->fd_in);
	if (head->fd_out != 1)
		close(head->fd_out);
	
	waitpid(pid, &status, 0);
	return (0);
}

int execute_from_list(t_token *head)
{
	char **args;
	char *cmd_path;
	int arg_count;

	head->fd_in = 0;
	head->fd_out = 1;
	if (handle_redirections(head) != 0)
		return (1);

	arg_count = count_args(head);
	args = create_args_array(head, arg_count);
	if (!args)
		return (1);

	cmd_path = find_command(args[0]);
	if (cmd_path)
	{
		execute_command(cmd_path, args, head);
		free(cmd_path);
	}
	else
		ft_printf("Command not found: %s\n", args[0]);

	free_args(args);
	return (0);
}

