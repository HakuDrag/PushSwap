/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 00:00:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/11/06 00:00:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fd_char(t_output *out, char c)
{
	ft_putchar_fd(c, out->fd);
	out->count++;
}

void	ft_fd_str(t_output *out, const char *str)
{
	if (!str)
		str = "(null)";
	while (*str)
		ft_fd_char(out, *str++);
}

void	ft_fd_base(t_output *out, unsigned long long value, char *base)
{
	unsigned long long	len;

	len = ft_strlen(base);
	if (value >= len)
		ft_fd_base(out, value / len, base);
	ft_fd_char(out, base[value % len]);
}

void	ft_fd_signed(t_output *out, int value)
{
	long long	number;

	number = value;
	if (number < 0)
	{
		ft_fd_char(out, '-');
		number = -number;
	}
	ft_fd_base(out, (unsigned long long)number, "0123456789");
}

void	ft_fd_pointer(t_output *out, void *ptr)
{
	if (!ptr)
		return (ft_fd_str(out, "(nil)"));
	ft_fd_str(out, "0x");
	ft_fd_base(out, (uintptr_t)ptr, "0123456789abcdef");
}
