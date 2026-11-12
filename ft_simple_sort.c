/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 00:00:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/11/05 00:00:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_simple_sort(t_stack *a, t_stack *b, t_options *options)
{
	int	i;

	i = 0;
	while (a->top)
	{
		while (i < b->size)
		{
			if (a->top->value > b->top->value)
				break ;
			rb(b, options);
			i++;
		}
		pb(a, b, options);
		while (i > 0)
		{
			rrb(b, options);
			i--;
		}
	}
	while (b->top)
		pa(a, b, options);
}
/*
static int	ft_bubble_pass(t_stack *a, t_options *options)
{
	int	i;
	int	swapped;

	i = 0;
	swapped = 0;
	while (i++ < a->size - 1)
	{
		if (a->top->value > a->top->next->value)
		{
			sa(a, options);
			swapped = 1;
		}
		ra(a, options);
	}
	ra(a, options);
	return (swapped);
}

void	ft_simple_sort(t_stack *a, t_options *options)
{
	int	i;

	i = 0;
	while (i++ < a->size)
	{
		if (!ft_bubble_pass(a, options))
			break ;
	}
}*/
