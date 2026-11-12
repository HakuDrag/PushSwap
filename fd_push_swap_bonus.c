/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_push_swap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 00:00:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/11/09 00:00:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fd_push_swap_bonus.h"

int	ft_allocate_options_bonus(int argc, char **argv, t_stack *a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!parse_values(argv[i], a))
			return (0);
		i++;
	}
	return (a->size > 0);
}

int	ft_prepare_bonus(int argc, char **argv, t_stack **a, t_stack **b)
{
	if (!ft_init_structs_bonus(a, b))
		return (0);
	if (!ft_allocate_options_bonus(argc, argv, *a)
		|| !ft_allocation_check(*a))
	{
		ft_delete_allocation_bonus(a, b);
		return (0);
	}
	return (1);
}

void	ft_push_swap_bonus(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return ;
	if (!ft_prepare_bonus(argc, argv, &a, &b))
	{
		ft_error();
		return ;
	}
	if (ft_sort_bonus(a, b))
		ft_error();
	else if (ft_is_sorted_bonus(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_delete_allocation_bonus(&a, &b);
}

int	ft_is_sorted_bonus(t_stack *a, t_stack *b)
{
	t_node	*current;

	if (!ft_is_empty(b))
		return (0);
	current = a->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	ft_push_swap_bonus(argc, argv);
	return (0);
}
