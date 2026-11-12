/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_init_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 00:00:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/11/09 00:00:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fd_push_swap_bonus.h"

int	ft_init_structs_bonus(t_stack **a, t_stack **b)
{
	*a = malloc(sizeof(t_stack));
	if (!*a)
		return (0);
	*b = malloc(sizeof(t_stack));
	if (!*b)
	{
		free(*a);
		*a = NULL;
		return (0);
	}
	ft_init_stack(*a);
	ft_init_stack(*b);
	return (1);
}

static void	ft_delete_stack_bonus(t_stack **stack)
{
	t_node	*deleted;
	t_node	*next;

	if (!stack || !*stack)
		return ;
	deleted = (*stack)->top;
	while (deleted)
	{
		next = deleted->next;
		free(deleted);
		deleted = next;
	}
	free(*stack);
	*stack = NULL;
}

void	ft_delete_allocation_bonus(t_stack **a, t_stack **b)
{
	ft_delete_stack_bonus(a);
	ft_delete_stack_bonus(b);
}
