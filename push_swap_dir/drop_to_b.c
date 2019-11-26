/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drop_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 21:07:10 by nharra            #+#    #+#             */
/*   Updated: 2019/11/26 01:42:25 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"
#include "push_swap.h"

void		init_info(t_stack *stack, t_info *info)
{
	t_dlist		*ptr;

	info->min = stack->beg;
	info->max = stack->beg;
	info->stack = stack;
	ptr = stack->beg->next;
	while(ptr)
	{
		if (ptr->tag > info->max->tag)
			info->max = ptr;
		if (ptr->tag < info->min->tag)
			info->min = ptr;
		ptr = ptr->next;
	}
}

void	drop_to_b(t_stack *a, t_stack *b)
{
	t_info	a_info;

	init_info(a, &a_info);
	while (a_info.stack->size > 2)
	{
		if (a_info.stack->beg == a_info.max ||
		a_info.stack->beg == a_info.min)
		{
			rotate_op(a_info.stack);
			ft_putstr("ra\n");
		}
		else
		{
			push_op(a_info.stack, b);
			ft_putstr("pb\n");
		}
	}
}
