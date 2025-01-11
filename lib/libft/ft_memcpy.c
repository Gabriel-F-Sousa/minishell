/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:49:07 by gabferna          #+#    #+#             */
/*   Updated: 2023/10/05 09:49:09 by gabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	int		n;
	int		size;
	char	*cha_d;
	char	*cha_s;

	n = 0;
	size = len;
	cha_d = dest;
	cha_s = (char *)src;
	if (!cha_d && !cha_s)
		return (0);
	while (n < size)
	{
		cha_d[n] = cha_s[n];
		n++;
	}
	return (dest);
}
