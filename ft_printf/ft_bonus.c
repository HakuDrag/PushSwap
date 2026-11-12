/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 10:35:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/10/26 10:35:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_check(char temp)
{
	char	*special_signs;
	int		i;

	special_signs = "cspdiuxX%";
	i = 0;
	while (special_signs[i])
	{
		if (temp == special_signs[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_parse_number(char *format, int *step)
{
	int	number;

	number = 0;
	while (ft_isdigit(format[*step]))
	{
		number = number * 10 + (format[*step] - '0');
		(*step)++;
	}
	return (number);
}

static void	ft_parse_flags(char *format, int *step, t_format *list)
{
	while (format[*step] == '-' || format[*step] == '0'
		|| format[*step] == '#' || format[*step] == '+'
		|| format[*step] == ' ')
	{
		if (format[*step] == '-')
			list->left = 1;
		else if (format[*step] == '0')
			list->zero = 1;
		else if (format[*step] == '#')
			list->hash = 1;
		else if (format[*step] == '+')
			list->plus = 1;
		else if (format[*step] == ' ')
			list->space = 1;
		(*step)++;
	}
}

static void	t_format_creator(char *format, int *step, t_format *list)
{
	while (!ft_check(format[*step]) && format[*step])
	{
		ft_parse_flags(format, step, list);
		if (ft_isdigit(format[*step]))
		{
			list->width = ft_parse_number(format, step);
			continue ;
		}
		else if (format[*step] == '.')
		{
			(*step)++;
			list->precision = ft_parse_number(format, step);
		}
		else
			break ;
	}
	if (ft_check(format[*step]))
		list->spec = format[*step];
}

void	ft_parse(char *format, int *step, va_list *args, int *count)
{
	t_format	list;

	list = (t_format){0};
	list.precision = -1;
	t_format_creator(format, step, &list);
	fd_define(list.spec, args, count, &list);
}
