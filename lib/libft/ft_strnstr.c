/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:51:24 by gabferna          #+#    #+#             */
/*   Updated: 2023/10/03 13:51:26 by gabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t size)
{
	size_t			n;
	size_t			s;
	size_t			small_len;
	unsigned char	*_big;
	unsigned char	*_small;

	n = 0;
	s = 0;
	_big = (unsigned char *)big;
	_small = (unsigned char *)little;
	small_len = ft_strlen((char *)_small);
	if (small_len == 0 || little[0] == '\0')
		return ((char *)_big);
	while (_big[n] != '\0' && n < size)
	{
		while (_big[n + s] == _small[s] && s < size && s + n < size)
		{
			if (s == small_len -1)
				return ((char *)&_big[n]);
			s++;
		}
		s = 0;
		n++;
	}
	return (0);
}
