/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 00:00:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/11/05 00:00:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->size = 0;
}

int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	append_node(t_stack *a, int digit)
{
	t_node	*node;
	t_node	*last;

	node = malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->value = digit;
	node->index = a->size;
	node->next = NULL;
	if (!a->top)
		a->top = node;
	else
	{
		last = a->top;
		while (last->next)
			last = last->next;
		last->next = node;
	}
	a->size++;
	return (1);
}

int	ft_allocation_check(t_stack *a)
{
	t_node	*end;
	t_node	*start;

	start = a->top;
	while (start)
	{
		end = start->next;
		while (end)
		{
			if (start->value == end->value)
				return (0);
			end = end->next;
		}
		start = start->next;
	}
	return (1);
}

void	ft_delete_allocation(t_stack *a)
{
	t_node	*deleted;
	t_node	*next;

	deleted = a->top;
	while (deleted)
	{
		next = deleted->next;
		free(deleted);
		deleted = next;
	}
}
