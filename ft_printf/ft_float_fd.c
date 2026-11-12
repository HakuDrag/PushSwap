/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 00:00:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/11/06 00:00:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_float_digits(t_output *out, double value)
{
	unsigned long long	whole;
	unsigned int		decimals;

	whole = (unsigned long long)value;
	decimals = (unsigned int)((value - (double)whole) * 100 + 0.5);
	if (decimals == 100)
	{
		whole++;
		decimals = 0;
	}
	ft_fd_base(out, whole, "0123456789");
	ft_fd_char(out, '.');
	ft_fd_char(out, '0' + decimals / 10);
	ft_fd_char(out, '0' + decimals % 10);
}

void	ft_fd_float(t_output *out, double value)
{
	if (value != value)
		return (ft_fd_str(out, "nan"));
	if (value < 0)
	{
		ft_fd_char(out, '-');
		value = -value;
	}
	if (value >= 10000000000000000.0)
		return (ft_fd_str(out, "inf"));
	ft_float_digits(out, value);
}
