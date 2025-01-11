/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:07:33 by gabferna          #+#    #+#             */
/*   Updated: 2023/10/27 13:07:35 by gabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	convert_base(unsigned long nbr, char *base, unsigned int size)
{
	unsigned long	n;
	char			a;

	n = nbr;
	if (n >= size)
		convert_base(n / size, base, size);
	a = base[n % size];
	write(1, &a, 1);
}

static size_t	count_num(unsigned long num)
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

int	ft_print_ptr(void *ptr)
{
	unsigned long	address;

	address = (unsigned long)ptr;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	convert_base(address, "0123456789abcdef", 16);
	return (count_num(address) + 2);
}
