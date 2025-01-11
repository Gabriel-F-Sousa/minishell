/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:06:44 by gabferna          #+#    #+#             */
/*   Updated: 2023/10/05 12:06:48 by gabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	unsigned char	*cha1;
	unsigned char	*cha2;
	int				n;

	n = 0;
	cha1 = (unsigned char *)s1;
	cha2 = (unsigned char *)s2;
	while (n < (int)len)
	{
		if (cha1[n] != cha2[n])
			return (cha1[n] - cha2[n]);
		n++;
	}
	return (0);
}
