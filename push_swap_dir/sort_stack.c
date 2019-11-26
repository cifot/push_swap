/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:48:30 by nharra            #+#    #+#             */
/*   Updated: 2019/11/26 12:01:14 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"
#include "push_swap.h"

static void		rotate(t_stack *a, size_t count_ra)
{
	size_t		count_rra;

	count_rra = a->size - count_ra;
	if (count_ra < count_rra)
	{
		while(count_ra)
		{
			rotate_op(a);
			ft_putstr("ra\n");
			--count_ra;
		}
	}
	else
	{
		while(count_rra)
		{
			rev_rotate_op(a);
			ft_putstr("rra\n");
			--count_rra;
		}
	}
}

static void		check_rotate(t_stack *a)
{
	t_dlist		*ptr;
	size_t		count_ra;

	ptr = a->beg;
	count_ra = 1;
	while (ptr->next && ptr->next->tag > ptr->tag)
	{
		++count_ra;
		ptr = ptr->next;
	}
	if (ptr->next == NULL)
		return ;
	rotate(a, count_ra);
}

void			sort_stack(t_stack *a, t_stack *b)
{
	t_op_cost	cost;

	if (ft_dlist_is_tagsort(a->beg, 1))
		return ;
	drop_to_b(a, b);
	while(b->size != 0)
	{
		find_min_cost(&cost, a, b);
		min_cost_to_a(&cost, a, b);
	}
	check_rotate(a);
}
