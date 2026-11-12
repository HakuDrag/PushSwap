/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 00:00:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/11/05 00:00:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	quick_sort_b(t_stack *a, t_stack *b, int count, t_options *options);

static void	quick_sort_a(t_stack *a, t_stack *b, int count, t_options *options)
{
	int	count_b;

	if (count < 2)
		return ;
	if (count == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a, options);
		return ;
	}
	count_b = ft_partition_a(a, b, count, options);
	quick_sort_a(a, b, count - count_b, options);
	quick_sort_b(a, b, count_b, options);
}

static void	quick_sort_b(t_stack *a, t_stack *b, int count, t_options *options)
{
	int	count_a;

	if (count == 0)
		return ;
	if (count == 1)
	{
		pa(a, b, options);
		return ;
	}
	if (count == 2)
	{
		if (b->top->value < b->top->next->value)
			sb(b, options);
		pa(a, b, options);
		pa(a, b, options);
		return ;
	}
	count_a = ft_partition_b(a, b, count, options);
	quick_sort_a(a, b, count_a, options);
	quick_sort_b(a, b, count - count_a, options);
}

void	ft_complex_sort(t_stack *a, t_stack *b, t_options *options)
{
	quick_sort_a(a, b, a->size, options);
}
