/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_simple_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:59:53 by nharra            #+#    #+#             */
/*   Updated: 2019/10/21 00:17:41 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

static void		sort_a_min_last(t_stack *a)
{
	if (a->beg->tag < a->beg->next->tag)
	{
		ft_putstr("rra\n");
		rev_rotate_op(a);
	}
	else
	{
		ft_putstr("sa\nrra\n");
		swap_op(a);
		rev_rotate_op(a);
	}
}

static void		sort_a_min_second(t_stack *a)
{
	if (a->beg->tag < a->beg->next->next->tag)
	{
		ft_putstr("sa\n");
		swap_op(a);
	}
	else
	{
		ft_putstr("ra\n");
		rotate_op(a);
	}
}

static void		sort_simple_3a(t_stack *a)
{
	if (a->beg->next->next->tag < a->beg->next->tag
	&& a->beg->next->next->tag < a->beg->tag)
	{
		sort_a_min_last(a);
	}
	else if (a->beg->next->tag < a->beg->tag
	&& a->beg->next->tag < a->beg->next->next->tag)
	{
		sort_a_min_second(a);
	}
	else
	{
		ft_putstr("rra\nsa\n");
		rev_rotate_op(a);
		swap_op(a);
	}
}

int				check_simple_a(t_stack *a, size_t size_a)
{
	if (size_a > 3)
		return (0);
	if (size_a == 2)
	{
		if (a->beg->tag > a->beg->next->tag)
		{
			ft_putstr("sa\n");
			swap_op(a);
		}
	}
	else if (a->size == 3)
		sort_simple_3a(a);
	else if (size_a == 3)
		sort_hard_3a(a);
	return (1);
}
