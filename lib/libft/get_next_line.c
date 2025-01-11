/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:05:59 by gabferna          #+#    #+#             */
/*   Updated: 2023/11/07 12:30:37 by gabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
#include "libft.h"

void	free_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

static char	*read_text(int fd, char *sbuffer)
{
	char	*templine;
	int		n_read;

	templine = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!templine)
		return (0);
	n_read = 1;
	while (!ft_line_strchr(sbuffer, '\n') && n_read > 0)
	{
		n_read = read(fd, templine, BUFFER_SIZE);
		if (n_read < 0)
		{
			free(sbuffer);
			free(templine);
			return (0);
		}
		templine[n_read] = '\0';
		sbuffer = ft_line_strjoin(sbuffer, templine);
	}
	free(templine);
	return (sbuffer);
}

static char	*get_line(char *sbuffer)
{
	int		i;
	char	*str;

	i = 0;
	if (!sbuffer[i])
		return (0);
	while (sbuffer[i] && sbuffer[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (0);
	i = 0;
	while (sbuffer[i] && sbuffer[i] != '\n')
	{
		str[i] = sbuffer[i];
		i++;
	}
	if (sbuffer[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

static char	*remove_line(char	*sbuffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!sbuffer)
		return (0);
	while (sbuffer[i] && sbuffer[i] != '\n')
		i++;
	while (!sbuffer[i] || sbuffer[i + 1] == '\0')
	{
		free(sbuffer);
		return (0);
	}
	str = malloc(sizeof(char) * (ft_strlen(sbuffer) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (sbuffer[i])
		str[j++] = sbuffer[i++];
	str[j] = '\0';
	free(sbuffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*sbuffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	sbuffer = read_text(fd, sbuffer);
	if (!sbuffer)
		return (0);
	line = get_line(sbuffer);
	sbuffer = remove_line(sbuffer);
	return (line);
}

// int main()
// {	
// 	int	fd = open("get_next_line.c", O_RDONLY);
// 	char *test;
// 	int lines;
// 	lines = 1;
// 	while ((test = get_next_line(fd)))
// 	{
// 		lines++;
// 		printf("%s", test);
// 	}
// 	printf("%d\n", lines);
// 	return 0;
// }