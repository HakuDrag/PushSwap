/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 00:00:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/11/05 00:00:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

double	count_disorder(t_stack *a)
{
	t_node	*start;
	t_node	*end;
	double	inversions;

	if (a->size < 2)
		return (0.0);
	inversions = 0.0;
	start = a->top;
	while (start)
	{
		end = start->next;
		while (end)
		{
			if (start->value > end->value)
				inversions++;
			end = end->next;
		}
		start = start->next;
	}
	return (inversions / ((double)a->size * (a->size - 1) / 2.0));
}

void	ft_sort(t_stack *a, t_options *options)
{
	t_stack	b;

	ft_init_stack(&b);
	options->s_bench.disorder = count_disorder(a);
	if (options->s_bench.disorder == 0.0)
		return ;
	if (options->option == COMPLEX
		|| (options->option == ADAPTIVE
			&& options->s_bench.disorder >= 0.5))
		ft_complex_sort(a, &b, options);
	else if (options->option == MEDIUM
		|| (options->option == ADAPTIVE
			&& options->s_bench.disorder >= 0.2))
		ft_medium_sort(a, &b, options);
	else if (options->option == SIMPLE
		|| (options->option == ADAPTIVE
			&& options->s_bench.disorder > 0.0))
		ft_simple_sort(a, &b, options);
}
