/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: callwood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:41:54 by callwood          #+#    #+#             */
/*   Updated: 2026/11/03 13:41:58 by callwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_do_rab(t_stack *stack)
{
	t_node	*first;
	t_node	*tmp;

	if (!ft_has_enough(stack))
		return ;
	first = stack->top;
	tmp = stack->top;
	while (tmp->next)
		tmp = tmp->next;
	stack->top = first->next;
	tmp->next = first;
	first->next = NULL;
}

void	ra(t_stack *a, t_options *options)
{
	if (!ft_has_enough(a))
		return ;
	ft_do_rab(a);
	write(1, "ra\n", 3);
	ft_count_op(options, OP_RA);
}

void	rb(t_stack *b, t_options *options)
{
	if (!ft_has_enough(b))
		return ;
	ft_do_rab(b);
	write(1, "rb\n", 3);
	ft_count_op(options, OP_RB);
}

void	rr(t_stack *a, t_stack *b, t_options *options)
{
	if (!ft_has_enough(a) && !ft_has_enough(b))
		return ;
	ft_do_rab(a);
	ft_do_rab(b);
	write(1, "rr\n", 3);
	ft_count_op(options, OP_RR);
}
