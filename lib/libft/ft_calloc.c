/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:24:13 by gabferna          #+#    #+#             */
/*   Updated: 2023/10/06 10:24:14 by gabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*mem;

	mem = (void *)malloc(nitems * size);
	if (mem)
	{
		ft_bzero(mem, nitems * size);
	}
	return (mem);
}
