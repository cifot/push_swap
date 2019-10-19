/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hard_3b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 23:42:14 by nharra            #+#    #+#             */
/*   Updated: 2019/10/18 23:58:26 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"
#include "push_swap.h"

static void		sort_hard_3b(t_stack *b)
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
