/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 00:00:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/11/05 00:00:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_parse_flag(char *str, t_options *options)
{
	int	strategy;

	if (ft_strncmp(str, "bench", ft_strlen("bench") + 1) == 0)
	{
		options->bench = 1;
		return (1);
	}
	if (ft_strncmp(str, "simple", ft_strlen("simple") + 1) == 0)
		strategy = SIMPLE;
	else if (ft_strncmp(str, "medium", ft_strlen("medium") + 1) == 0)
		strategy = MEDIUM;
	else if (ft_strncmp(str, "complex", ft_strlen("complex") + 1) == 0)
		strategy = COMPLEX;
	else if (ft_strncmp(str, "adaptive", ft_strlen("adaptive") + 1) == 0)
		strategy = ADAPTIVE;
	else
		return (0);
	if (options->selected)
		return (0);
	options->option = strategy;
	options->selected = 1;
	return (1);
}

int	ft_allocate(int argc, char **argv, t_stack *a, t_options *options)
{
	int	slots;

	slots = 1;
	while (slots < argc)
	{
		if (argv[slots][0] == '-' && argv[slots][1] == '-')
		{
			if (!ft_parse_flag(argv[slots] + 2, options))
				return (0);
		}
		else if (!parse_values(argv[slots], a))
			return (0);
		slots++;
	}
	return (1);
}
