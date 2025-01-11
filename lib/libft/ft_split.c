/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:31:00 by gabferna          #+#    #+#             */
/*   Updated: 2024/12/15 10:19:59 by gabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_words(const char *s, char c)
{
	size_t	n;

	n = 0;
	while (*s)
	{
		if (*s != c)
		{
			++n;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (n);
}

char	**ft_split(const char *s, char c)
{
	char	**newstr;
	size_t	n;
	size_t	len;

	if (!s)
		return (0);
	n = 0;
	newstr = malloc(sizeof(char *) * (get_words(s, c) + 1));
	if (!newstr)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (s[len] && s[len] != c)
				++len;
			newstr[n++] = ft_substr(s, 0, len);
			s += len;
		}
		else
			++s;
	}
	newstr[n] = 0;
	return (newstr);
}
