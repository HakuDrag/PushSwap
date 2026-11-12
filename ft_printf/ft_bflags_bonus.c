/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bflags_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 10:35:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/10/26 10:35:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_print_paddr(uintptr_t poi, char *base, int *count)
{
	ft_padding('0', 1, count);
	ft_padding('x', 1, count);
	ft_print_base(poi, base, count);
}

static void	ft_print_nprefix(long int nbr, int *count, t_format *list)
{
	if (list->sign)
		ft_padding(list->sign, 1, count);
	if (list->hash && nbr != 0
		&& (list->spec == 'x' || list->spec == 'X'))
	{
		ft_padding('0', 1, count);
		ft_padding(list->spec, 1, count);
	}
}

void	ft_check_pflags(uintptr_t poi, char *base,
		int *count, t_format *list)
{
	int	len;

	if (poi == 0)
	{
		list->precision = -1;
		ft_check_sflags("(nil)", count, list);
		return ;
	}
	len = ft_base_count(poi, base) + 2;
	list->padding = list->width - len;
	if (list->padding < 0)
		list->padding = 0;
	if (!list->left)
		ft_padding(' ', list->padding, count);
	ft_print_paddr(poi, base, count);
	if (list->left)
		ft_padding(' ', list->padding, count);
}

void	ft_check_nflags(long int nbr, char *base,
		int *count, t_format *list)
{
	int	len;

	define_sign(&nbr, list);
	len = ft_base_count(nbr, base);
	if (nbr == 0 && list->precision == 0)
		len = 0;
	count_padding(len, list, nbr);
	if (!list->left && (!list->zero || list->precision >= 0))
		ft_padding(' ', list->padding, count);
	ft_print_nprefix(nbr, count, list);
	if (list->zero && !list->left && list->precision < 0)
		ft_padding('0', list->padding, count);
	if (list->precision > len)
		ft_padding('0', list->precision - len, count);
	if (len > 0)
		ft_print_base(nbr, base, count);
	if (list->left)
		ft_padding(' ', list->padding, count);
}

void	ft_check_sflags(char *str, int *count, t_format *list)
{
	int	len;

	if (!str)
	{
		str = "(null)";
		if (list->precision >= 0 && list->precision < 6)
			str = "";
	}
	len = ft_formator(str, list);
	list->padding = list->width - len;
	if (list->padding < 0)
		list->padding = 0;
	if (!list->left)
		ft_padding(' ', list->padding, count);
	write(1, str, len);
	*count += len;
	if (list->left)
		ft_padding(' ', list->padding, count);
}
