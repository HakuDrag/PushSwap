/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_execute_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 00:00:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/11/09 00:00:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fd_push_swap_bonus.h"

int	ft_execute_bonus(char *line, t_stack *a, t_stack *b)
{
	if (line[0] == 's')
		return (ft_execute_s_bonus(line, a, b));
	if (line[0] == 'p')
		return (ft_execute_p_bonus(line, a, b));
	if (line[0] == 'r')
		return (ft_execute_r_bonus(line, a, b));
	return (0);
}

int	ft_sort_bonus(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!ft_execute_bonus(line, a, b))
		{
			free(line);
			return (1);
		}
		free(line);
		line = get_next_line(0);
	}
	return (0);
}
