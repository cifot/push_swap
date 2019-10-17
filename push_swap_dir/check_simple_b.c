/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_simple_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:45:42 by nharra            #+#    #+#             */
/*   Updated: 2019/10/17 18:29:32 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

static void		sort_b_max_last(t_stack *b)
{
	if (b->beg->tag < b->beg->next->tag)
	{

		ft_putstr("rb\nsb\n");
		rotate_op(b);
		swap_op(b);
	}
	else
	{
		ft_putstr("rrb\n");
		rev_rotate_op(b);
	}
}

static void		sort_b_max_second(t_stack *b)
{
	if (b->beg->tag < b->beg->next->next->tag)
	{
		ft_putstr("rb\n");
		rotate_op(b);
	}
	else
	{
		ft_putstr("sb\n");
		swap_op(b);
	}
}

static void		sort_3b(t_stack *b)
{
	if (b->beg->next->next->tag > b->beg->next->tag
	&& b->beg->next->next->tag > b->beg->tag)
	{

		sort_b_max_last(b);
	}
	else if (b->beg->next->tag > b->beg->tag
	&& b->beg->next->tag > b->beg->next->next->tag)
	{
		sort_b_max_second(b);
	}
	else
	{
		ft_putstr("sb\nrb\n");
		swap_op(b);
		rotate_op(b);
	}

}

int				check_simple_b(t_stack *b)
{
	if (ft_dlist_is_tagsort(b->beg, 0))
		return (1);
	if (b->size > 3)
		return (0);
	if (b->size == 2)
	{
		if (b->beg->tag < b->beg->next->tag)
		{
			ft_putstr("sb\n");
			swap_op(b);
		}
	}
	else if (b->size == 3)
		sort_3b(b);
	return (1);
}
