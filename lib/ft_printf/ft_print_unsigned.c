/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:31:06 by gabferna          #+#    #+#             */
/*   Updated: 2023/10/27 11:31:08 by gabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	count_num(unsigned int num)
{
	unsigned int	n;

	n = 0;
	if (num <= 0)
		n++;
	while (num && ++n)
		num /= 10;
	return (n);
}

static char	*ft_uitoa(unsigned int n)
{
	char				*str;
	unsigned int		i;
	unsigned int		size;

	size = count_num(n);
	str = malloc(size + 1 * sizeof(char));
	if (!str)
		return (0);
	i = size - 1;
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[i] = '0' + (n % 10);
		n = (n / 10);
		i--;
	}
	str[size] = '\0';
	return (str);
}

int	ft_print_unsigned(unsigned int nbr)
{
	char	*str;
	int		n;

	str = ft_uitoa(nbr);
	n = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (n);
}
