/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:18:18 by gabferna          #+#    #+#             */
/*   Updated: 2023/10/05 11:18:20 by gabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	size_t		n;
	char		*cha;

	n = 0;
	cha = (char *)s;
	while (n < len)
	{
		if ((unsigned char)cha[n] == (unsigned char)c)
			return ((unsigned char *)&cha[n]);
		n++;
	}
	return (0);
}
