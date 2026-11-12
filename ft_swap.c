/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: callwood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:42:11 by callwood          #+#    #+#             */
/*   Updated: 2026/11/03 14:13:24 by callwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_do_swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!ft_has_enough(stack))
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

void	sa(t_stack *a, t_options *options)
{
	if (!ft_has_enough(a))
		return ;
	ft_do_swap(a);
	write(1, "sa\n", 3);
	ft_count_op(options, OP_SA);
}

void	sb(t_stack *b, t_options *options)
{
	if (!ft_has_enough(b))
		return ;
	ft_do_swap(b);
	write(1, "sb\n", 3);
	ft_count_op(options, OP_SB);
}

void	ss(t_stack *a, t_stack *b, t_options *options)
{
	if (!ft_has_enough(a) && !ft_has_enough(b))
		return ;
	ft_do_swap(a);
	ft_do_swap(b);
	write(1, "ss\n", 3);
	ft_count_op(options, OP_SS);
}
