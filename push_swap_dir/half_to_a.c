/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   half_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 23:31:21 by nharra            #+#    #+#             */
/*   Updated: 2019/10/21 00:57:57 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "stack.h"

static int		check_more(t_stack *a, size_t size, int middle)
{
	t_dlist *ptr;

	ptr = a->beg;
	while (size)
	{
		if (ptr->tag >= middle)
		{
			return (1);
		}
		--size;
		ptr = ptr->next;
	}
	return (0);
}

static void		take_rrb(t_stack *b, size_t to_b)
{
	if (b->size <= 3)
		return ;
	while(to_b)
	{
		rev_rotate_op(b);
		ft_putstr("rrb\n");
		--to_b;
	}
}

size_t			half_to_a(t_stack *a, t_stack *b, size_t size)
{
	int		middle;
	size_t	to_a;
	size_t	to_b;

	to_a = 0;
	to_b = 0;
	middle = find_middle(b, size);
	while (check_more(b, size, middle))
	{
		if (b->beg->tag >= middle)
		{
			push_op(b, a);
			ft_putstr("pa\n");
			++to_a;
		}
		else
		{
			rotate_op(b);
			ft_putstr("rb\n");
			++to_b;
		}
		size--;
	}
	take_rrb(b, to_b);
	return(to_a);
}
