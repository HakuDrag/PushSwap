/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: callwood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:41:35 by callwood          #+#    #+#             */
/*   Updated: 2026/11/03 13:41:39 by callwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_do_rrab(t_stack *stack)
{
	t_node	*last;
	t_node	*prev;

	if (!ft_has_enough(stack))
		return ;
	prev = NULL;
	last = stack->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
}

void	rra(t_stack *a, t_options *options)
{
	if (!ft_has_enough(a))
		return ;
	ft_do_rrab(a);
	write(1, "rra\n", 4);
	ft_count_op(options, OP_RRA);
}

void	rrb(t_stack *b, t_options *options)
{
	if (!ft_has_enough(b))
		return ;
	ft_do_rrab(b);
	write(1, "rrb\n", 4);
	ft_count_op(options, OP_RRB);
}

void	rrr(t_stack *a, t_stack *b, t_options *options)
{
	if (!ft_has_enough(a) && !ft_has_enough(b))
		return ;
	ft_do_rrab(a);
	ft_do_rrab(b);
	write(1, "rrr\n", 4);
	ft_count_op(options, OP_RRR);
}
