/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hard_3b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 23:42:14 by nharra            #+#    #+#             */
/*   Updated: 2019/10/19 14:10:21 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"
#include "push_swap.h"

static void		sort_b_max_last(t_stack *b, t_stack *a)
{
	if (b->beg->tag < b->beg->next->tag)
	{
		ft_putstr("rb\nsb\npa\npa\nrrb\npa\n");
		rotate_op(b);
		swap_op(b);
		push_op(b, a);
		push_op(b, a);
		rev_rotate_op(b);
		push_op(b, a);
	}
	else
	{
		ft_putstr("rb\nsb\npa\nrrb\npa\npa\n");
		rotate_op(b);
		swap_op(b);
		push_op(b, a);
		rev_rotate_op(b);
		push_op(b, a);
		push_op(b, a);
	}
}

static void		sort_b_max_second(t_stack *b, t_stack *a)
{
	if (b->beg->tag < b->beg->next->next->tag)
	{
		ft_putstr("sb\npa\nsb\npa\npa\n");
		swap_op(b);
		push_op(b, a);
		swap_op(b);
		push_op(b, a);
		push_op(b, a);
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

void			sort_hard_3b(t_stack *b, t_stack *a)
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
		ft_putstr("pa\nsb\npb\npb\n");
		push_op(b, a);
		swap_op(b);
		push_op(b, a);
		push_op(b, a);
	}
}
