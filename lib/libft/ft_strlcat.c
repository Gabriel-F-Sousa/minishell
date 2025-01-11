/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:15:56 by gabferna          #+#    #+#             */
/*   Updated: 2023/10/03 12:15:58 by gabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_size;
	unsigned int	src_size;
	unsigned int	n;	

	src_size = ft_strlen(src);
	dest_size = ft_strlen(dest);
	n = 0;
	if (dest_size >= size)
		return (size + src_size);
	while (src[n] != '\0' && dest_size + n < size - 1)
	{
		dest[n + dest_size] = src[n];
		n++;
	}
	dest[n + dest_size] = '\0';
	return (dest_size + src_size);
}
