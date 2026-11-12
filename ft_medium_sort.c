/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 00:00:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/11/05 00:00:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	get_chunk_size(int size)
{
	int	chunk_size;

	chunk_size = 0;
	if (size <= 100)
		chunk_size = size / 3;
	else
		chunk_size = size / 12;
	if (chunk_size < 1)
		chunk_size = 1;
	return (chunk_size);
}

int	get_max_index(t_stack *b)
{
	t_node	*tmp;
	int		max_ind;
	int		max_i;
	int		i;

	if (!b || ft_is_empty(b))
		return (0);
	tmp = b->top;
	max_ind = tmp->index;
	max_i = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->index > max_ind)
		{
			max_ind = tmp->index;
			max_i = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (max_i);
}

void	empty_b_to_a(t_stack *a, t_stack *b, t_options *options)
{
	int	max_i;
	int	size;

	while (b && b->size > 0)
	{
		max_i = get_max_index(b);
		size = b->size;
		if (max_i <= size / 2)
		{
			while (max_i-- > 0)
				rb(b, options);
		}
		else
		{
			while (max_i++ < size)
				rrb(b, options);
		}
		pa(a, b, options);
	}
}

static int	ft_process_top(t_stack *a, t_stack *b, int limits[2],
		t_options *options)
{
	if (a->top->index <= limits[0])
	{
		pb(a, b, options);
		return (1);
	}
	else if (a->top->index <= limits[0] + limits[1])
	{
		pb(a, b, options);
		rb(b, options);
		return (1);
	}
	return (0);
}

void	ft_medium_sort(t_stack *a, t_stack *b, t_options *options)
{
	int	i;
	int	rot;
	int	limits[2];

	if (!a || a->size <= 1)
		return ;
	i = 0;
	rot = 0;
	limits[1] = get_chunk_size(a->size);
	while (a->size > 0)
	{
		limits[0] = i;
		if (ft_process_top(a, b, limits, options) || ++rot >= a->size)
		{
			i++;
			rot = 0;
		}
		else
			ra(a, options);
	}
	empty_b_to_a(a, b, options);
}
