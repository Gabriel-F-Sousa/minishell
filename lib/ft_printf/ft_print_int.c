/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:52:09 by gabferna          #+#    #+#             */
/*   Updated: 2023/10/27 09:52:11 by gabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_print_int(int nbr)
{
	ft_putnbr_fd(nbr, 1);
	return (count_num(nbr));
}
