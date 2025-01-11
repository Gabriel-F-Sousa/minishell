/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:24:29 by gabferna          #+#    #+#             */
/*   Updated: 2023/10/12 12:24:32 by gabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;

	i = 0;
	if (ft_strlen(s) <= start)
	{
		return (ft_strdup(""));
	}
	if (ft_strlen(s) < len)
	{
		len = ft_strlen(s);
	}
	if (ft_strlen(s) <= start + len)
		len = ft_strlen(s) - start;
	newstr = malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (0);
	while (s[start] && i < len)
		newstr[i++] = s[start++];
	newstr[i] = '\0';
	return (newstr);
}
