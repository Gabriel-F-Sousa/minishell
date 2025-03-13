#include "../minishell.h"

char	*check_direct_path(char *cmd)
{
	char	*path;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
		{
			path = ft_strdup(cmd);
			return (path);
		}
	}
	return (NULL);
}

char	*get_path_var(void)
{
	char	*path;

	path = getenv("PATH");
	if (!path)
		return (NULL);
	return (ft_strdup(path));
}

char	*create_full_path(char *dir, char *cmd)
{
	char	*temp;
	char	*full_path;

	temp = ft_strjoin(dir, "/");
	if (!temp)
		return (NULL);
	full_path = ft_strjoin(temp, cmd);
	free(temp);
	return (full_path);
}

char	*try_paths(char *path, char *cmd)
{
	char	*path_copy;
	char	*dir;
	char	*full_path;

	path_copy = path;
	while (1)
	{
		dir = ft_strsep(&path_copy, ":");
		if (!dir)
			break ;
		full_path = create_full_path(dir, cmd);
		if (!full_path)
		{
			free(path);
			return (NULL);
		}
		if (access(full_path, X_OK) == 0)
		{
			free(path);
			return (full_path);
		}
		free(full_path);
	}
	free(path);
	return (NULL);
}

char	*find_command(char *cmd)
{
	char	*path;

	if (!cmd)
		return (NULL);
	path = check_direct_path(cmd);
	if (path)
		return (path);
	path = get_path_var();
	if (!path)
		return (NULL);
	return (try_paths(path, cmd));
}
