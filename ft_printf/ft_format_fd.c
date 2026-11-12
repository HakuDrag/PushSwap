/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 00:00:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/11/06 00:00:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fd_define_number(char spec, va_list *args, t_output *out)
{
	if (spec == 'd' || spec == 'i')
		ft_fd_signed(out, va_arg(*args, int));
	else if (spec == 'u')
		ft_fd_base(out, va_arg(*args, unsigned int), "0123456789");
	else if (spec == 'x')
		ft_fd_base(out, va_arg(*args, unsigned int), "0123456789abcdef");
	else if (spec == 'X')
		ft_fd_base(out, va_arg(*args, unsigned int), "0123456789ABCDEF");
	else if (spec == 'f')
		ft_fd_float(out, va_arg(*args, double));
}

static void	fd_define(char spec, va_list *args, t_output *out)
{
	if (spec == 'c')
		ft_fd_char(out, (char)va_arg(*args, int));
	else if (spec == 's')
		ft_fd_str(out, va_arg(*args, char *));
	else if (spec == 'p')
		ft_fd_pointer(out, va_arg(*args, void *));
	else if (spec == '%')
		ft_fd_char(out, '%');
	else
		fd_define_number(spec, args, out);
}

int	ft_format_output(int fd, const char *format, va_list *args)
{
	t_output	out;
	int			i;

	out.fd = fd;
	out.count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == '.' && format[i + 1] == '2'
				&& format[i + 2] == 'f')
				i += 2;
			fd_define(format[i], args, &out);
		}
		else if (format[i] != '%')
			ft_fd_char(&out, format[i]);
		if (format[i])
			i++;
	}
	return (out.count);
}
