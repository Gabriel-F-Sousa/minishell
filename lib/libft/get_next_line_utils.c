/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:07:22 by gabferna          #+#    #+#             */
/*   Updated: 2023/11/03 10:07:28 by gabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include "get_next_line.h"

char	*ft_line_strjoin(char *left_str, char *right_str)
{
	char	*str;
	size_t	i;
	size_t	j;
	int		size;

	i = -1;
	j = 0;
	if (!left_str)
	{
		left_str = malloc(sizeof(char) * 1);
		left_str[0] = '\0';
	}
	if (!left_str || !right_str)
		return (0);
	size = ft_strlen(left_str) + ft_strlen(right_str);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	while (left_str[++i] != '\0')
		str[i] = left_str[i];
	while (right_str[j] != '\0')
		str[i++] = right_str[j++];
	str[i] = '\0';
	free(left_str);
	return (str);
}

char	*ft_line_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
