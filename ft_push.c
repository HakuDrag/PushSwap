/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: callwood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:41:15 by callwood          #+#    #+#             */
/*   Updated: 2026/11/03 13:41:21 by callwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_do_push(t_stack *first, t_stack *second)
{
	t_node	*tmp;

	tmp = second->top;
	second->top = second->top->next;
	second->size--;
	tmp->next = first->top;
	first->top = tmp;
	first->size++;
}

void	pa(t_stack *a, t_stack *b, t_options *options)
{
	if (ft_is_empty(b))
		return ;
	ft_do_push(a, b);
	write(1, "pa\n", 3);
	ft_count_op(options, OP_PA);
}

void	pb(t_stack *a, t_stack *b, t_options *options)
{
	if (ft_is_empty(a))
		return ;
	ft_do_push(b, a);
	write(1, "pb\n", 3);
	ft_count_op(options, OP_PB);
}
