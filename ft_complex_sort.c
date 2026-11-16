/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 00:00:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/11/16 00:00:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void		quick_sort_a(t_stack *a, t_stack *b, int count, t_options *options);

static void	sort_three_full(t_stack *a, t_options *options)
{
	int	slot1;
	int	slot2;
	int	slot3;

	slot1 = a->top->value;
	slot2 = a->top->next->value;
	slot3 = a->top->next->next->value;
	if (slot1 > slot2 && slot2 > slot3)
	{
		sa(a, options);
		rra(a, options);
	}
	else if (slot1 > slot3 && slot3 > slot2)
		ra(a, options);
	else if (slot2 > slot1 && slot1 > slot3)
		rra(a, options);
	else if (slot2 > slot3 && slot3 > slot1)
	{
		sa(a, options);
		ra(a, options);
	}
	else if (slot1 > slot2)
		sa(a, options);
}

static void	sort_three_a(t_stack *a, t_stack *b, t_options *options)
{
	t_node	*slot1;
	t_node	*slot2;
	t_node	*slot3;

	slot1 = a->top;
	slot2 = slot1->next;
	slot3 = slot2->next;
	if (slot1->value > slot2->value)
		sa(a, options);
	slot1 = a->top;
	slot2 = slot1->next;
	slot3 = slot2->next;
	if (slot2->value > slot3->value)
	{
		pb(a, b, options);
		sa(a, options);
		pa(a, b, options);
	}
	slot1 = a->top;
	slot2 = slot1->next;
	if (slot1->value > slot2->value)
		sa(a, options);
}

static void	sort_three_b(t_stack *a, t_stack *b, t_options *options)
{
	t_node	*slot1;
	t_node	*slot2;
	t_node	*slot3;

	slot1 = b->top;
	slot2 = slot1->next;
	slot3 = slot2->next;
	if (slot1->value < slot2->value)
		sb(b, options);
	slot1 = b->top;
	slot2 = slot1->next;
	slot3 = slot2->next;
	if (slot2->value < slot3->value)
	{
		pa(a, b, options);
		sb(b, options);
		pb(a, b, options);
	}
	slot1 = b->top;
	slot2 = slot1->next;
	if (slot1->value < slot2->value)
		sb(b, options);
	pa(a, b, options);
	pa(a, b, options);
	pa(a, b, options);
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
	if (count == 3)
	{
		sort_three_b(a, b, options);
		return ;
	}
	count_a = ft_partition_b(a, b, count, options);
	quick_sort_a(a, b, count_a, options);
	quick_sort_b(a, b, count - count_a, options);
}

void	quick_sort_a(t_stack *a, t_stack *b, int count, t_options *options)
{
	int		count_b;

	if (count < 2)
		return ;
	if (count == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a, options);
		return ;
	}
	if (count == 3)
	{
		if (a->size == 3)
			sort_three_full(a, options);
		else
			sort_three_a(a, b, options);
		return ;
	}
	count_b = ft_partition_a(a, b, count, options);
	quick_sort_a(a, b, count - count_b, options);
	quick_sort_b(a, b, count_b, options);
}
