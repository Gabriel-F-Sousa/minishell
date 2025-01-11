/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 09:46:16 by gabferna          #+#    #+#             */
/*   Updated: 2023/10/13 09:46:19 by gabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	newstr = malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (0);
	ft_strlcpy(newstr, (char *)s1, len + 1);
	ft_strlcat(newstr, (char *)s2, len + 1);
	return (newstr);
}
