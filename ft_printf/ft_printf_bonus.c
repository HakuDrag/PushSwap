/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 10:35:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/10/26 10:35:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_check_cflags(int c, int *count, t_format *list)
{
	int	padding;

	padding = 0;
	if (list && list->width > 1)
		padding = list->width - 1;
	if (list && !list->left)
		ft_padding(' ', padding, count);
	ft_putchar_fd((char)c, 1);
	(*count)++;
	if (list && list->left)
		ft_padding(' ', padding, count);
}

static void	fd_define_number(char temp, va_list *args,
		int *count, t_format *list)
{
	if (temp == 'd' || temp == 'i')
		ft_check_nflags((long int)va_arg(*args, int),
			"0123456789", count, list);
	else if (temp == 'u')
		ft_check_nflags((long int)va_arg(*args, unsigned int),
			"0123456789", count, list);
	else if (temp == 'x')
		ft_check_nflags((long int)va_arg(*args, unsigned int),
			"0123456789abcdef", count, list);
	else if (temp == 'X')
		ft_check_nflags((long int)va_arg(*args, unsigned int),
			"0123456789ABCDEF", count, list);
}

void	fd_define(char temp, va_list *args, int *count, t_format *list)
{
	if (temp == '\0')
		return ;
	if (temp == 'c')
		ft_check_cflags(va_arg(*args, int), count, list);
	else if (temp == 's')
		ft_check_sflags(va_arg(*args, char *), count, list);
	else if (temp == 'p')
		ft_check_pflags((uintptr_t)va_arg(*args, void *),
			"0123456789abcdef", count, list);
	else if (temp == '%')
	{
		ft_putchar_fd('%', 1);
		(*count)++;
	}
	else
		fd_define_number(temp, args, count, list);
}

static void	ft_walk_format(const char *format, va_list *args, int *count)
{
	int	step;

	step = 0;
	while (format[step])
	{
		if (format[step] == '%')
		{
			step++;
			if (!format[step])
				break ;
			ft_parse((char *)format, &step, args, count);
			if (!format[step])
				break ;
		}
		else
		{
			ft_putchar_fd(format[step], 1);
			(*count)++;
		}
		step++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	ft_walk_format(format, &args, &count);
	va_end(args);
	return (count);
}
