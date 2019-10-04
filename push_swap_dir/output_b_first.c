/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_b_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:51:37 by nharra            #+#    #+#             */
/*   Updated: 2019/10/04 12:51:38 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"

void			last_1b(t_stack *a, t_stack *b)
{
	ft_putendl("pa");
	stack_push(a, b, "pa");
}

void			last_2b(t_stack *a, t_stack *b)
{
	if (b->data[b->n] < b->data[b->n - 1])
	{
		ft_putendl("sb");
		stack_swap(a, b, "sb");
	}
	ft_putendl("pa");
	stack_push(a, b, "pa");
	ft_putendl("pa");
	stack_push(a, b, "pa");
}

static void		last_3b_dop(t_stack *a, t_stack *b)
{
	ft_putendl("rb");
	stack_rotate(a, b, "rb");
	ft_putendl("sb");
	stack_swap(a, b, "sb");
	ft_putendl("pa");
	stack_push(a, b, "pa");
	ft_putendl("rrb");
	stack_rotate(a, b, "rrb");
	last_2b(a, b);
}

static void		last_3b_dop2(t_stack *a, t_stack *b)
{
	ft_putendl("rrb");
	stack_rotate(a, b, "rrb");
	ft_putendl("pa");
	stack_push(a, b, "pa");
	last_2b(a, b);
}

void			last_3b(t_stack *a, t_stack *b)
{
	if (b->data[b->n] > b->data[b->n - 1] && b->data[b->n] > b->data[b->n - 2])
	{
		ft_putendl("pa");
		stack_push(a, b, "pa");
		last_2b(a, b);
	}
	else if (b->data[b->n - 1] > b->data[b->n] &&
		b->data[b->n - 1] > b->data[b->n - 2])
	{
		ft_putendl("sb");
		stack_swap(a, b, "sb");
		ft_putendl("pa");
		stack_push(a, b, "pa");
		last_2b(a, b);
	}
	else if (b->data[b->n - 2] > b->data[b->n] &&
			b->data[b->n - 2] > b->data[b->n - 1] && b->n != 3)
	{
		last_3b_dop(a, b);
	}
	else if (b->data[b->n - 2] > b->data[b->n] &&
			b->data[b->n - 2] > b->data[b->n - 1] && b->n == 3)
	{
		last_3b_dop2(a, b);
	}
}
