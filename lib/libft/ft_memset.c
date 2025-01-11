/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:13:59 by gabferna          #+#    #+#             */
/*   Updated: 2023/10/04 12:14:00 by gabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t size)
{
	int		n;
	char	*_str;
	int		len;

	n = 0;
	len = size;
	_str = (char *)str;
	while (n < len)
	{
		_str[n] = c;
		n++;
	}
	return (_str);
}
