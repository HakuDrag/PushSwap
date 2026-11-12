/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 11:30:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/10/19 10:47:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_length;

	s_length = ft_strlen(s);
	if (start >= s_length)
		len = 0;
	else if (len > s_length - start)
		len = s_length - start;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	if (len > 0)
		ft_memcpy(str, &s[start], len);
	str[len] = '\0';
	return (str);
}
