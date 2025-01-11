/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:18:03 by gabferna          #+#    #+#             */
/*   Updated: 2023/10/26 13:18:05 by gabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *fmt, ...);
int		ft_print_int(int n);
int		ft_print_hex(int nbr, int cap);
int		ft_print_unsigned(unsigned int nbr);
int		ft_print_ptr(void *ptr);
int		ft_print_str(char *str);

#endif
