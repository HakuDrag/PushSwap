/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 11:30:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/10/19 10:47:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*source;
	unsigned char		*dst;

	if (dest == src)
		return (dest);
	source = src;
	dst = dest;
	if (dst > source)
	{
		i = n;
		while (i > 0)
		{
			i--;
			dst[i] = source[i];
		}
		return (dest);
	}
	return (ft_memcpy(dest, src, n));
}
