/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 10:35:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/10/26 10:35:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_output
{
	int	fd;
	int	count;
}	t_output;

int		ft_printf(const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_format_output(int fd, const char *format, va_list *args);
void	ft_fd_char(t_output *out, char c);
void	ft_fd_str(t_output *out, const char *str);
void	ft_fd_base(t_output *out, unsigned long long value, char *base);
void	ft_fd_signed(t_output *out, int value);
void	ft_fd_pointer(t_output *out, void *ptr);
void	ft_fd_float(t_output *out, double value);
void	ft_print_base(uintptr_t n, char *digits, int *count);
void	ft_print_number(int n, char *digits, int *count);
void	ft_print_par(uintptr_t n, char *digits, int *count);
int		ft_base_count(uintptr_t nbr, char *base);
void	ft_print_str(char *str, int *count);

#endif
