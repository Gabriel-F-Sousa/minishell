/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabferna <gabferna@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:28:43 by gabferna          #+#    #+#             */
/*   Updated: 2023/10/18 10:28:45 by gabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		n;
	int		size;
	char	*newstr;

	n = 0;
	size = ft_strlen(s);
	newstr = malloc(size + 1 * sizeof(char));
	if (!newstr)
		return (0);
	while (s[n] != '\0')
	{
		newstr[n] = f(n, s[n]);
		n++;
	}
	newstr[n] = '\0';
	return (newstr);
}
