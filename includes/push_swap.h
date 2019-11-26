/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:50:33 by nharra            #+#    #+#             */
/*   Updated: 2019/11/26 01:36:25 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# define COUNT_WAY 4
# define RA_RB 0
# define RA_RRB 1
# define RRA_RB 2
# define RRA_RRB 3

typedef struct	s_info
{
	t_dlist		*min;
	t_dlist		*max;
	t_stack		*stack;
}				t_info;

typedef struct	s_op_cost
{
	size_t		ra;
	size_t		rb;
	size_t		rra;
	size_t		rrb;
	size_t		min_cost;
	size_t		way;
}				t_op_cost;

void			sort_stack(t_stack *a, t_stack *b);
void			drop_to_b(t_stack *a, t_stack *b);
void			min_cost_to_a(t_op_cost *cost, t_stack *a, t_stack *b);
void			find_min_cost(t_op_cost *cost, t_stack *a, t_stack *b);

#endif
