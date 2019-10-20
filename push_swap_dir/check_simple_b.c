/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_simple_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:45:42 by nharra            #+#    #+#             */
/*   Updated: 2019/10/21 00:25:39 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"
#include "push_swap.h"

static void		sort_b_max_last(t_stack *b, t_stack *a)
{
	if (b->beg->tag < b->beg->next->tag)
	{
		ft_putstr("rb\nsb\npa\npa\npa\n");
		rotate_op(b);
		swap_op(b);
		push_op(b, a);
		push_op(b, a);
		push_op(b, a);
	}
	else
	{
		ft_putstr("rrb\npa\npa\npa\n");
		rev_rotate_op(b);
		push_op(b, a);
		push_op(b, a);
		push_op(b, a);
	}
}

static void		sort_b_max_second(t_stack *b, t_stack *a)
{
	if (b->beg->tag < b->beg->next->next->tag)
	{
		ft_putstr("rb\npa\npa\npa\n");
		push_op(b, a);
		push_op(b, a);
		push_op(b, a);
		rotate_op(b);
	}
	else
	{
		ft_putstr("sb\npa\npa\npa\n");
		swap_op(b);
		push_op(b, a);
		push_op(b, a);
		push_op(b, a);
	}
}

static void		sort_simple_3b(t_stack *b, t_stack *a)
{
	if (b->beg->next->next->tag > b->beg->next->tag
	&& b->beg->next->next->tag > b->beg->tag)
	{
		sort_b_max_last(b, a);
	}
	else if (b->beg->next->tag > b->beg->tag
	&& b->beg->next->tag > b->beg->next->next->tag)
	{
		sort_b_max_second(b, a);
	}
	else
	{
		ft_putstr("pa\nsb\npa\npa\n");
		push_op(b, a);
		swap_op(b);
		push_op(b, a);
		push_op(b, a);
	}
}

int				check_simple_b(t_stack *b, t_stack *a, size_t size_b)
{
	if (size_b > 3)
		return (0);
	if (size_b == 2)
	{
		if (b->beg->tag < b->beg->next->tag)
		{
			ft_putstr("sb\n");
			swap_op(b);

		}
		ft_putstr("pa\npa\n");
		push_op(b, a);
		push_op(b, a);
	}
	else if (b->size == 3)
		sort_simple_3b(b, a);
	else if (size_b == 3)
		sort_hard_3b(b, a);
	return (1);
}
