/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 00:00:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/11/06 00:00:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	count = ft_format_output(1, format, &args);
	va_end(args);
	return (count);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		count;

	if (fd < 0 || !format)
		return (-1);
	va_start(args, format);
	count = ft_format_output(fd, format, &args);
	va_end(args);
	return (count);
}
