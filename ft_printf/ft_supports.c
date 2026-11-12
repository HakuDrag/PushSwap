/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supports.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 10:35:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/10/26 10:35:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_base(uintptr_t n, char *digits, int *count)
{
	uintptr_t	base;

	base = ft_strlen(digits);
	if (n >= base)
		ft_print_base(n / base, digits, count);
	(*count)++;
	ft_putchar_fd(digits[n % base], 1);
}

int	ft_base_count(uintptr_t nbr, char *base)
{
	int			len;
	uintptr_t	base_len;

	len = 1;
	base_len = ft_strlen(base);
	while (nbr >= base_len)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}

void	ft_print_number(int n, char *digits, int *count)
{
	unsigned int	number;

	number = n;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		(*count)++;
		number = -number;
	}
	ft_print_base(number, digits, count);
}

void	ft_print_par(uintptr_t n, char *digits, int *count)
{
	if (n)
	{
		ft_putstr_fd("0x", 1);
		*count += 2;
		ft_print_base(n, digits, count);
	}
	else
		ft_print_str("(nil)", count);
}

void	ft_print_str(char *str, int *count)
{
	if (str == NULL)
		str = "(null)";
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
}
