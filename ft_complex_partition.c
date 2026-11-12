/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_partition.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 00:00:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/11/05 00:00:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_rank_in_group(t_stack *stack, int value, int count)
{
	t_node	*temp;
	int		rank;
	int		i;

	temp = stack->top;
	rank = 0;
	i = 0;
	while (i++ < count)
	{
		if (temp->value < value)
			rank++;
		temp = temp->next;
	}
	return (rank);
}

static int	ft_pivot(t_stack *stack, int count)
{
	t_node	*temp;
	int		i;

	temp = stack->top;
	i = 0;
	while (i++ < count)
	{
		if (ft_rank_in_group(stack, temp->value, count)
			== count / 2)
			return (temp->value);
		temp = temp->next;
	}
	return (stack->top->value);
}

static void	ft_restore(t_stack *stack, int rotated,
		int is_a, t_options *options)
{
	while (rotated--)
	{
		if (is_a)
			rra(stack, options);
		else
			rrb(stack, options);
	}
}

int	ft_partition_a(t_stack *a, t_stack *b, int count, t_options *options)
{
	int	pivot;
	int	moved;
	int	i;

	pivot = ft_pivot(a, count);
	moved = 0;
	i = 0;
	while (i++ < count)
	{
		if (a->top->value <= pivot)
		{
			pb(a, b, options);
			moved++;
		}
		else
			ra(a, options);
	}
	if (a->size > count - moved)
		ft_restore(a, count - moved, 1, options);
	return (moved);
}

int	ft_partition_b(t_stack *a, t_stack *b, int count, t_options *options)
{
	int	pivot;
	int	moved;
	int	i;

	pivot = ft_pivot(b, count);
	moved = 0;
	i = 0;
	while (i++ < count)
	{
		if (b->top->value >= pivot)
		{
			pa(a, b, options);
			moved++;
		}
		else
			rb(b, options);
	}
	if (b->size > count - moved)
		ft_restore(b, count - moved, 0, options);
	return (moved);
}
