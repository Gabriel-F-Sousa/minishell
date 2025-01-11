/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabferna <gabferna@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:21:29 by gabferna          #+#    #+#             */
/*   Updated: 2023/10/14 12:21:31 by gabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_num(int num)
{
	int	n;

	n = 0;
	if (num <= 0)
		n++;
	while (num && ++n)
		num /= 10;
	return (n);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		neg;
	int		size;

	neg = 0;
	size = count_num(n);
	str = malloc(size + 1 * sizeof(char));
	if (!str)
		return (0);
	i = size - 1;
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		neg = 1;
	while (n != 0)
	{
		str[i] = '0' + abs(n % 10);
		n = (n / 10);
		i--;
	}
	if (neg)
		str[i] = '-';
	str[size] = '\0';
	return (str);
}
