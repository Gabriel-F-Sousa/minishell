/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:31:31 by gabferna          #+#    #+#             */
/*   Updated: 2024/12/10 02:18:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	int		n;
	int		sign;
	long	res;

	res = 0;
	sign = 1;
	n = 0;
	while ((str[n] >= 9 && str[n] <= 13) || str[n] == 32)
	{
		n++;
	}
	if (str[n] == '-' || str[n] == '+')
	{
		if (str[n] == '-')
			sign *= -1;
		n++;
	}
	while (str[n] >= '0' && str[n] <= '9')
	{
		res = (res * 10) + (str[n] - 48);
		n++;
	}
	return (sign * res);
}
