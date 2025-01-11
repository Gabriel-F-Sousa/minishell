/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:36:57 by gabferna          #+#    #+#             */
/*   Updated: 2023/10/05 10:36:59 by gabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	void	*ret;

	if (!dest && !src)
		return (0);
	ret = dest;
	if (src < dest)
	{
		src += len;
		dest += len;
		while (len--)
			*(char *)--dest = *(char *)--src;
	}
	else
		while (len--)
			*(char *)dest++ = *(char *)src++;
	return (ret);
}
