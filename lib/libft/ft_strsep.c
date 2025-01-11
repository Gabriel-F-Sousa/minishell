/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:16:30 by codespace         #+#    #+#             */
/*   Updated: 2024/12/29 17:19:30 by gabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_delim(char c, const char *delim)
{
	while (*delim)
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

char	*ft_strsep(char **stringp, const char *delim)
{
	char	*start;
	char	*end;

	if (!stringp || !*stringp)
		return (NULL);
	start = *stringp;
	end = start;
	while (*end && !is_delim(*end, delim))
		end++;
	if (*end)
	{
		*end = '\0';
		*stringp = end + 1;
	}
	else
		*stringp = NULL;
	return (start);
}
