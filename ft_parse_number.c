/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 00:00:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/11/05 00:00:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_set_digit(int *digit, unsigned int number, int sign)
{
	if (sign < 0 && number == (unsigned int)INT_MAX + 1)
		*digit = INT_MIN;
	else if (sign < 0)
		*digit = -(int)number;
	else
		*digit = number;
}

static int	parse_digits(char *str, size_t *pos, int *digit, int sign)
{
	unsigned int	number;
	unsigned int	limit;
	int				next;

	number = 0;
	limit = INT_MAX;
	if (sign < 0)
		limit = (unsigned int)INT_MAX + 1;
	while (ft_isdigit(str[*pos]))
	{
		next = str[(*pos)++] - '0';
		if (number > limit / 10 || (number == limit / 10
				&& (unsigned int)next > limit % 10))
			return (0);
		number = number * 10 + next;
	}
	ft_set_digit(digit, number, sign);
	return (1);
}

int	parse_number(char *str, size_t *pos, int *digit)
{
	int	sign;

	sign = 1;
	if (str[*pos] == '-' || str[*pos] == '+')
	{
		if (str[*pos] == '-')
			sign = -1;
		(*pos)++;
	}
	if (!ft_isdigit(str[*pos]))
		return (0);
	if (!parse_digits(str, pos, digit, sign))
		return (0);
	if (str[*pos] && !is_space(str[*pos]))
		return (0);
	return (1);
}

int	parse_values(char *str, t_stack *a)
{
	size_t	pos;
	int		digit;
	int		count;

	pos = 0;
	count = 0;
	while (str[pos])
	{
		while (is_space(str[pos]))
			pos++;
		if (!str[pos])
			break ;
		if (!parse_number(str, &pos, &digit))
			return (0);
		if (!append_node(a, digit))
			return (0);
		count++;
	}
	return (count > 0);
}
