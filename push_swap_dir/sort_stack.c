/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:48:30 by nharra            #+#    #+#             */
/*   Updated: 2019/10/17 14:08:38 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"
#include "push_swap.h"
#include <stdio.h>

void	half_to_b(t_stack *a,  t_stack *b, size_t  size)
{
	size_t i;
	int		middle;

	i = 0;
	middle = find_middle(a, size);
	while(i < size)
	{
		if (a->beg->tag >= middle)
		{
			rotate_op(a);
			ft_putstr("ra\n");
		}
		else
		{
			push_op(a, b);
			ft_putstr("pb\n");
		}
		++i;
	}
}

void	all_to_a_with_rotate(t_stack *a, t_stack *b, size_t size_a)
{
	size_t size;

	size = b->size;

	while(size_a)
	{
		ft_putendl("rra");
		rev_rotate_op(a);
		--size_a;
	}
	while(b->size)
	{
		ft_putendl("pa");
		push_op(b, a);
	}
	while(size)
	{
		ft_putendl("ra");
		rotate_op(a);
		--size;
	}
}

void	all_to_a(t_stack *a, t_stack *b, size_t size_a)
{
	while(size_a)
	{
		ft_putendl("rra");
		rev_rotate_op(a);
		--size_a;
	}
	while(b->size)
	{
		ft_putendl("pa");
		push_op(b, a);
	}
}

void	sort_stack(t_stack *a, t_stack *b, size_t size)
{
	size_t size_b;
	size_t size_a;

	if ((ft_dlist_is_tagsort(a->beg, 1) && b->size == 0)||
		check_simple_a(a, size))
		return ;
	half_to_b(a, b, size);
	size_b = b->size;
	size_a = size - size_b;
	if (ft_dlist_is_tagsort(b->beg, 0))
	{
		all_to_a_with_rotate(a, b, size_a);
		sort_stack(a, b, size_a);

	}
	else
	{
		all_to_a(a, b, size_a);
		sort_stack(a, b, size_b);
		sort_stack(a, b, size_a);
	}
}
