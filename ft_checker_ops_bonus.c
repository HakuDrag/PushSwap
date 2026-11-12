/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_ops_bonus.c                              :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 00:00:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/11/09 00:00:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fd_push_swap_bonus.h"

int	ft_execute_s_bonus(char *line, t_stack *a, t_stack *b)
{
	if (ft_strncmp(line, "sa\n", ft_strlen("sa\n") + 1) == 0)
		ft_do_swap(a);
	else if (ft_strncmp(line, "sb\n", ft_strlen("sb\n") + 1) == 0)
		ft_do_swap(b);
	else if (ft_strncmp(line, "ss\n", ft_strlen("ss\n") + 1) == 0)
	{
		ft_do_swap(a);
		ft_do_swap(b);
	}
	else
		return (0);
	return (1);
}

int	ft_execute_p_bonus(char *line, t_stack *a, t_stack *b)
{
	if (ft_strncmp(line, "pa\n", ft_strlen("pa\n") + 1) == 0)
	{
		if (b->size > 0)
			ft_do_push(a, b);
	}
	else if (ft_strncmp(line, "pb\n", ft_strlen("pb\n") + 1) == 0)
	{
		if (a->size > 0)
			ft_do_push(b, a);
	}
	else
		return (0);
	return (1);
}

static int	ft_execute_rr_bonus(char *line, t_stack *a, t_stack *b)
{
	if (ft_strncmp(line, "rra\n", ft_strlen("rra\n") + 1) == 0)
		ft_do_rrab(a);
	else if (ft_strncmp(line, "rrb\n", ft_strlen("rrb\n") + 1) == 0)
		ft_do_rrab(b);
	else if (ft_strncmp(line, "rrr\n", ft_strlen("rrr\n") + 1) == 0)
	{
		ft_do_rrab(a);
		ft_do_rrab(b);
	}
	else
		return (0);
	return (1);
}

int	ft_execute_r_bonus(char *line, t_stack *a, t_stack *b)
{
	if (ft_strncmp(line, "ra\n", ft_strlen("ra\n") + 1) == 0)
		ft_do_rab(a);
	else if (ft_strncmp(line, "rb\n", ft_strlen("rb\n") + 1) == 0)
		ft_do_rab(b);
	else if (ft_strncmp(line, "rr\n", ft_strlen("rr\n") + 1) == 0)
	{
		ft_do_rab(a);
		ft_do_rab(b);
	}
	else
		return (ft_execute_rr_bonus(line, a, b));
	return (1);
}
