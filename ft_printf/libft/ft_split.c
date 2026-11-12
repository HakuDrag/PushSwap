/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 11:30:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/10/19 10:47:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_slots(char const *s, char c)
{
	size_t	slots;
	size_t	i;

	i = 0;
	slots = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			slots++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (slots);
}

static void	ft_free_words(char **arr, size_t slots)
{
	while (slots > 0)
	{
		slots--;
		free(arr[slots]);
	}
	free(arr);
}

static int	ft_add_word(char **arr, const char *s, char c, size_t *i)
{
	size_t	start;
	size_t	end;

	while (s[*i] && s[*i] == c)
		(*i)++;
	start = *i;
	end = start;
	while (s[end] && s[end] != c)
		end++;
	*i = end;
	if (start == end)
		return (0);
	*arr = malloc(end - start + 1);
	if (!*arr)
		return (-1);
	ft_memcpy(*arr, s + start, end - start);
	(*arr)[end - start] = '\0';
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	count;
	int		status;
	char	**arr;

	arr = ft_calloc(ft_count_slots(s, c) + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	count = 0;
	while (s[i])
	{
		status = ft_add_word(&arr[count], s, c, &i);
		if (status < 0)
		{
			ft_free_words(arr, count);
			return (NULL);
		}
		count += status;
	}
	arr[count] = NULL;
	return (arr);
}
