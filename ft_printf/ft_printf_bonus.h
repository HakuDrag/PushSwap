/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 10:35:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/10/26 10:35:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "ft_printf.h"

typedef struct s_format
{
	int		width;
	int		precision;
	int		left;
	int		zero;
	int		hash;
	int		plus;
	int		space;
	int		padding;
	char	sign;
	char	spec;
}			t_format;

void	fd_define(char temp, va_list *args, int *count, t_format *list);
void	ft_parse(char *format, int *step, va_list *args, int *count);
void	count_padding(int len, t_format *list, long int nbr);
void	ft_padding(char c, int len, int *count);
int		ft_formator(char *str, t_format *list);
void	define_sign(long int *nbr, t_format *list);
void	ft_check_sflags(char *str, int *count, t_format *list);
void	ft_check_nflags(long int nbr, char *base,
			int *count, t_format *list);
void	ft_check_pflags(uintptr_t poi, char *base,
			int *count, t_format *list);

#endif
