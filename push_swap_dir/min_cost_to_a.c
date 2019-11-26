/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_cost_to_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 01:07:46 by nharra            #+#    #+#             */
/*   Updated: 2019/11/26 02:02:22 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"
#include "push_swap.h"
#include <stdio.h>

static void		op_ra_rb(t_op_cost *cost, t_stack *a, t_stack *b)
{
	size_t	rr_count;

	rr_count = cost->ra > cost->rb ? cost->rb : cost->ra;
	cost->ra -= rr_count;
	cost->rb -= rr_count;
	while(rr_count)
	{
		rotate_op(a);
		rotate_op(b);
		ft_putstr("rr\n");
		--rr_count;
	}
	while(cost->rb)
	{
		rotate_op(b);
		ft_putstr("rb\n");
		--cost->rb;
	}
	while(cost->ra)
	{
		rotate_op(a);
		ft_putstr("ra\n");
		--cost->ra;
	}
}

static void		op_rra_rrb(t_op_cost *cost, t_stack *a, t_stack *b)
{
	size_t	rrr_count;

	rrr_count = cost->rra > cost->rrb ? cost->rrb : cost->rra;
	cost->rra -= rrr_count;
	cost->rrb -= rrr_count;
	while(rrr_count)
	{
		rev_rotate_op(a);
		rev_rotate_op(b);
		ft_putstr("rrr\n");
		--rrr_count;
	}
	while(cost->rrb)
	{
		rev_rotate_op(b);
		ft_putstr("rrb\n");
		--cost->rrb;
	}
	while(cost->rra)
	{
		rev_rotate_op(a);
		ft_putstr("rra\n");
		--cost->rra;
	}
}

static void		op_ra_rrb(t_op_cost *cost, t_stack *a, t_stack *b)
{
	while(cost->ra)
	{
		rotate_op(a);
		ft_putstr("ra\n");
		--cost->ra;
	}
	while(cost->rrb)
	{
		rev_rotate_op(b);
		ft_putstr("rrb\n");
		--cost->rrb;
	}
}

static void		op_rra_rb(t_op_cost *cost, t_stack *a, t_stack *b)
{
	while(cost->rra)
	{
		rev_rotate_op(a);
		ft_putstr("rra\n");
		--cost->rra;
	}
	while(cost->rb)
	{
		rotate_op(b);
		ft_putstr("rb\n");
		--cost->rb;
	}
}

void			min_cost_to_a(t_op_cost *cost, t_stack *a, t_stack *b)
{
	if (cost->way == RA_RB)
		op_ra_rb(cost, a, b);
	else if (cost->way == RA_RRB)
		op_ra_rrb(cost, a, b);
	else if (cost->way == RRA_RB)
		op_rra_rb(cost, a, b);
	else if (cost->way == RRA_RRB)
		op_rra_rrb(cost, a, b);
	push_op(b, a);
	ft_putstr("pa\n");
}
