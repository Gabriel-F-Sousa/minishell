/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 09:48:28 by gabferna          #+#    #+#             */
/*   Updated: 2023/10/07 09:48:31 by gabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	int		n;
	char	*newstr;
	int		size;

	n = 0;
	size = ft_strlen(s) + 1;
	newstr = malloc(sizeof(char) * size);
	if (newstr)
	{
		while (n < (int) sizeof(char) * size)
		{
			newstr[n] = s[n];
			n++;
		}
	}
	return (newstr);
}
