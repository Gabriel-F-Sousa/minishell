/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 09:47:46 by gabferna          #+#    #+#             */
/*   Updated: 2023/10/25 09:47:48 by gabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	format(char fmt, va_list args)
{
	if (fmt == '%')
		return (write(1, "%", 1));
	else if (fmt == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	else if (fmt == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (fmt == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	else if (fmt == 'd' || fmt == 'i')
		return (ft_print_int(va_arg(args, int)));
	else if (fmt == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (fmt == 'X')
		return (ft_print_hex(va_arg(args, int), 1));
	else if (fmt == 'x')
		return (ft_print_hex(va_arg(args, int), 0));
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		n_printed;
	int		index;

	n_printed = 0;
	index = 0;
	va_start(ap, fmt);
	while (fmt[index])
	{
		if (fmt[index] == '%')
		{
			index++;
			n_printed += format(fmt[index], ap);
		}
		else
			n_printed += write(1, &fmt[index], 1);
		index++;
	}
	va_end(ap);
	return (n_printed);
}
