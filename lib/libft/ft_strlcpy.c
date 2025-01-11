/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:50:26 by gabferna          #+#    #+#             */
/*   Updated: 2023/10/03 10:50:30 by gabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	n;

	n = 0;
	if (size > 0)
	{
		while ((char)src[n] != '\0' && n < size - 1)
		{
			dst[n] = (char)src[n];
			n++;
		}
		dst[n] = 0;
	}
	while ((char)src[n] != '\0')
		n++;
	return (n);
}
