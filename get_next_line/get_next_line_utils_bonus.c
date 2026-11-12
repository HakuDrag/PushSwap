/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:00:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/10/26 15:00:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*source;
	unsigned char		*dst;

	i = 0;
	source = src;
	dst = dest;
	while (i < n)
	{
		dst[i] = source[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	len1 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len2 == SIZE_MAX || len1 > SIZE_MAX - len2 - 1)
		return (free(s1), NULL);
	result = malloc(len1 + len2 + 1);
	if (!result)
		return (free(s1), NULL);
	if (s1)
		ft_memcpy(result, s1, len1);
	ft_memcpy(result + len1, s2, len2);
	result[len1 + len2] = '\0';
	free(s1);
	return (result);
}

int	ft_set_end(char *buffer)
{
	size_t	i;

	if (!buffer)
		return (0);
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_line_count(char *stash)
{
	size_t	i;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}
