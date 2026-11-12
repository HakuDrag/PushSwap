/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsupports_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 10:35:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/10/26 10:35:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	count_padding(int len, t_format *list, long int nbr)
{
	list->padding = list->width - len;
	if (list->precision > len)
		list->padding -= list->precision - len;
	if (list->hash && (list->spec == 'x' || list->spec == 'X')
		&& nbr != 0)
		list->padding -= 2;
	if (list->sign)
		list->padding--;
	if (list->padding < 0)
		list->padding = 0;
}

void	ft_padding(char c, int len, int *count)
{
	while (len > 0)
	{
		ft_putchar_fd(c, 1);
		(*count)++;
		len--;
	}
}

int	ft_formator(char *str, t_format *list)
{
	int	len;

	len = ft_strlen(str);
	if (list->precision >= 0 && list->precision < len)
		len = list->precision;
	return (len);
}

void	define_sign(long int *nbr, t_format *list)
{
	if (list->spec != 'd' && list->spec != 'i')
		return ;
	if (*nbr < 0)
	{
		list->sign = '-';
		*nbr = -*nbr;
	}
	else if (list->plus)
		list->sign = '+';
	else if (list->space)
		list->sign = ' ';
}
