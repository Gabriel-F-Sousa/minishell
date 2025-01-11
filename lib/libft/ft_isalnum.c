/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:38:47 by gabferna          #+#    #+#             */
/*   Updated: 2023/10/03 12:38:49 by gabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_number(int cha)
{
	if (cha >= 48 && cha <= 57)
		return (1);
	return (0);
}

static int	is_letter(int cha)
{
	if ((cha >= 65 && cha <= 90) || (cha >= 97 && cha <= 122))
		return (1);
	return (0);
}

int	ft_isalnum(int cha)
{
	if (is_number(cha) || is_letter(cha))
		return (cha);
	return (0);
}
