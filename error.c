/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 00:00:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/11/05 00:00:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	ft_is_empty(t_stack *stack)
{
	if (!stack || !stack->top)
		return (1);
	return (0);
}

int	ft_has_enough(t_stack *stack)
{
	if (!stack || !stack->top || !stack->top->next)
		return (0);
	return (1);
}
