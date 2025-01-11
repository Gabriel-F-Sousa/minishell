/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:07:41 by gabferna          #+#    #+#             */
/*   Updated: 2023/10/03 12:07:43 by gabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t			n;
	unsigned char	*cha1;
	unsigned char	*cha2;

	n = 0;
	cha1 = (unsigned char *)s1;
	cha2 = (unsigned char *)s2;
	if (len <= 0)
		return (0);
	while (cha1[n] && cha2[n] && n < len)
	{
		if (cha1[n] != cha2[n])
			return (cha1[n] - cha2[n]);
		++n;
	}
	if (n == len)
		n--;
	return (cha1[n] - cha2[n]);
}
