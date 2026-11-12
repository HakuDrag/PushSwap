/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 11:30:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/10/19 10:47:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_length_count(long num)
{
	int	length;

	length = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num = -num;
		length++;
	}
	while (num > 0)
	{
		length++;
		num /= 10;
	}
	return (length);
}

static void	ft_fill_number(char *str, long num, int length)
{
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	if (num == 0)
		str[--length] = '0';
	while (num > 0)
	{
		str[--length] = (num % 10) + '0';
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		length;
	long	num;

	num = n;
	length = ft_length_count(num);
	str = malloc(length + 1);
	if (!str)
		return (NULL);
	ft_fill_number(str, num, length);
	str[length] = '\0';
	return (str);
}
