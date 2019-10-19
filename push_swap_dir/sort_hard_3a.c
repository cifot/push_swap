/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hard_3a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 13:20:56 by nharra            #+#    #+#             */
/*   Updated: 2019/10/19 14:10:12 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"
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
		ft_putstr("ra\nsa\nrra\nsa\n");
		rotate_op(a);
        swap_op(a);
        rev_rotate_op(a);
        swap_op(a);
	}
	else
	{
		ft_putstr("sa\nra\nsa\nrra\nsa\n");
        swap_op(a);
		rotate_op(a);
        swap_op(a);
        rev_rotate_op(a);
        swap_op(a);
	}
}

void			sort_hard_3a(t_stack *a)
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
		ft_putstr("ra\nsa\nrra\n");
		rotate_op(a);
		swap_op(a);
        rev_rotate_op(a);
	}
}