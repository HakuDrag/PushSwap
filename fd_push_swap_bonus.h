/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_push_swap_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 00:00:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/11/09 00:00:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FD_PUSH_SWAP_BONUS_H
# define FD_PUSH_SWAP_BONUS_H

# include "ft_push_swap.h"
# include "get_next_line/get_next_line.h"

int		ft_init_structs_bonus(t_stack **a, t_stack **b);
int		ft_allocate_options_bonus(int argc, char **argv, t_stack *a);
void	ft_delete_allocation_bonus(t_stack **a, t_stack **b);
int		ft_sort_bonus(t_stack *a, t_stack *b);
int		ft_execute_bonus(char *line, t_stack *a, t_stack *b);
int		ft_execute_s_bonus(char *line, t_stack *a, t_stack *b);
int		ft_execute_p_bonus(char *line, t_stack *a, t_stack *b);
int		ft_execute_r_bonus(char *line, t_stack *a, t_stack *b);
int		ft_is_sorted_bonus(t_stack *a, t_stack *b);
void	ft_push_swap_bonus(int argc, char **argv);

#endif
