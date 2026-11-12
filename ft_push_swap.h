/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: callwood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:45:54 by callwood          #+#    #+#             */
/*   Updated: 2026/11/03 13:46:00 by callwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "ft_printf.h"
# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
/* Structs */
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

enum				e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
};

enum				e_operation
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
};

typedef struct s_bench
{
	int				operations[OP_COUNT];
	int				total;
	double			disorder;
}					t_bench;

typedef struct s_options
{
	int				option;
	int				bench;
	int				selected;
	t_bench			s_bench;
}					t_options;

/* Errors */
int					ft_error(void);
int					ft_is_empty(t_stack *stack);
int					ft_has_enough(t_stack *stack);
/* Main logic */
void				ft_init_stack(t_stack *stack);
void				ft_sort(t_stack *a, t_options *options);
double				count_disorder(t_stack *a);
int					is_space(char c);
int					append_node(t_stack *a, int digit);
int					parse_number(char *str, size_t *pos, int *digit);
int					parse_values(char *str, t_stack *a);
int					ft_parse_flag(char *str, t_options *options);
int					ft_allocation_check(t_stack *a);
int					ft_allocate(int argc, char **argv, t_stack *a,
						t_options *options);
void				ft_delete_allocation(t_stack **a, t_options *options);
void				ft_push_swap(int argc, char **argv);
void				ft_simple_sort(t_stack *a, t_stack *b, t_options *options);
void				ft_medium_sort(t_stack *a, t_stack *b, t_options *options);
void				ft_assign_index(t_stack *a);
void				ft_complex_sort(t_stack *a, t_stack *b, t_options *options);
int					ft_partition_a(t_stack *a, t_stack *b, int count,
						t_options *options);
int					ft_partition_b(t_stack *a, t_stack *b, int count,
						t_options *options);
/* Stack operations */
void				ft_do_swap(t_stack *stack);
void				ft_do_push(t_stack *first, t_stack *second);
void				ft_do_rab(t_stack *stack);
void				ft_do_rrab(t_stack *stack);
void				ft_count_op(t_options *options, int op);
void				sa(t_stack *a, t_options *options);
void				sb(t_stack *b, t_options *options);
void				ss(t_stack *a, t_stack *b, t_options *options);
void				pa(t_stack *a, t_stack *b, t_options *options);
void				pb(t_stack *a, t_stack *b, t_options *options);
void				ra(t_stack *a, t_options *options);
void				rb(t_stack *b, t_options *options);
void				rr(t_stack *a, t_stack *b, t_options *options);
void				rra(t_stack *a, t_options *options);
void				rrb(t_stack *b, t_options *options);
void				rrr(t_stack *a, t_stack *b, t_options *options);

#endif
