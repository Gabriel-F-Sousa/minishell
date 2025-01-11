/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:24:20 by gabferna          #+#    #+#             */
/*   Updated: 2023/10/27 10:24:22 by gabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	convert_base(unsigned int nbr, char *base, unsigned int size)
{
	unsigned int	n;
	char			a;

	n = nbr;
	if (n >= size)
		convert_base(n / size, base, size);
	a = base[n % size];
	write(1, &a, 1);
}

static size_t	count_num(unsigned int num)
{
	size_t	n;

	n = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		n++;
		num /= 16;
	}
	return (n);
}

int	ft_print_hex(int nbr, int cap)
{
	if (cap)
		convert_base(nbr, "0123456789ABCDEF", 16);
	else
		convert_base(nbr, "0123456789abcdef", 16);
	return (count_num(nbr));
}
