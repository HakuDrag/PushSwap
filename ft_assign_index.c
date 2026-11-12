/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/050 00:0:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/11/05 00:00:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_assign_index(t_stack *a)
{
	t_node	*cur;
	t_node	*cmp;
	int		rank;

	cur = a->top;
	while (cur)
	{
		rank = 0;
		cmp = a->top;
		while (cmp)
		{
			if (cmp->value < cur->value)
				rank++;
			cmp = cmp->next;
		}
		cur->index = rank;
		cur = cur->next;
	}
}
