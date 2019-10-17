/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:48:30 by nharra            #+#    #+#             */
/*   Updated: 2019/10/17 22:18:56 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"
#include "push_swap.h"
#include <stdio.h>

static int		check_more(t_stack *a, size_t size, int middle)
{
	t_dlist *ptr;

	ptr = a->beg;
	while(size)
	{
		if  (ptr->tag < middle)
		{
			return (1);
		}
		--size;
		ptr =  ptr->next;
	}
	return (0);
}

static void		half_to_b(t_stack *a,  t_stack *b, size_t  size)
{
	size_t	i;
	int		middle;

	i = size;
	middle = find_middle(a, size);
	while(check_more(a, i, middle))
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
		i--;
	}
	i = size - b->size - i;
	if (size != a->size)
		while(i--)
		{
			rev_rotate_op(a);
			ft_putstr("rra\n");
		}
}

void	all_to_a_with_rotate(t_stack *a, t_stack *b)
{
	size_t size;

	size = b->size;
	while(b->size)
	{
		ft_putstr("pa\n");
		push_op(b, a);
	}
	while(size)
	{
		ft_putstr("ra\n");
		rotate_op(a);
		--size;
	}
}

void	all_to_a(t_stack *a, t_stack *b)
{
	while(b->size)
	{
		ft_putstr("pa\n");
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
	if (check_simple_b(b))
	{
		all_to_a_with_rotate(a, b);
		sort_stack(a, b, size_a);
	}
	else
	{
		all_to_a(a, b);
		sort_stack(a, b, size_b);
		sort_stack(a, b, size_a);
	}
}
