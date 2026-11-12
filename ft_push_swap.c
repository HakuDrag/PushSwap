/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 00:00:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/11/05 00:00:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	fd_bench_strategy(t_options *options)
{
	int	strategy;

	strategy = options->option;
	if (strategy == ADAPTIVE)
	{
		if (options->s_bench.disorder >= 0.5)
			strategy = COMPLEX;
		else if (options->s_bench.disorder >= 0.2)
			strategy = MEDIUM;
		else
			strategy = SIMPLE;
		ft_dprintf(2, "[bench] Strategy: Adaptive -> ");
	}
	else
		ft_dprintf(2, "[bench] Strategy: ");
	if (strategy == SIMPLE)
		ft_dprintf(2, "Simple (O(n^2))\n");
	else if (strategy == MEDIUM)
		ft_dprintf(2, "Medium (O(n sqrt(n)))\n");
	else
		ft_dprintf(2, "Complex (O(n log n))\n");
}

static void	fd_bench_operations(t_options *options)
{
	char	*names[OP_COUNT];
	int		i;

	names[OP_SA] = "sa";
	names[OP_SB] = "sb";
	names[OP_SS] = "ss";
	names[OP_PA] = "pa";
	names[OP_PB] = "pb";
	names[OP_RA] = "ra";
	names[OP_RB] = "rb";
	names[OP_RR] = "rr";
	names[OP_RRA] = "rra";
	names[OP_RRB] = "rrb";
	names[OP_RRR] = "rrr";
	i = 0;
	while (i < OP_COUNT)
	{
		ft_dprintf(2, "[bench] %s: %d\n", names[i],
			options->s_bench.operations[i]);
		i++;
	}
}

void	fd_bench(t_options *options)
{
	ft_dprintf(2, "[bench] Disorder: %f%%\n", options->s_bench.disorder
		* 100.0);
	fd_bench_strategy(options);
	ft_dprintf(2, "[bench] Total operations: %d\n", options->s_bench.total);
	fd_bench_operations(options);
}

static void	ft_init_structs(t_stack *a, t_options *options)
{
	ft_init_stack(a);
	options->bench = 0;
	options->selected = 0;
	options->option = ADAPTIVE;
	options->s_bench = (t_bench){0};
	options->s_bench.disorder = -1.0;
}

void	ft_push_swap(int argc, char **argv)
{
	t_stack		a;
	t_options	options;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	ft_init_structs(&a, &options);
	if (!ft_allocate(argc, argv, &a, &options) || a.size == 0
		|| !ft_allocation_check(&a))
	{
		ft_delete_allocation(&a);
		ft_error();
		exit(EXIT_FAILURE);
	}
	ft_assign_index(&a);
	ft_sort(&a, &options);
	if (options.bench == 1)
		fd_bench(&options);
	ft_delete_allocation(&a);
	exit(EXIT_SUCCESS);
}
