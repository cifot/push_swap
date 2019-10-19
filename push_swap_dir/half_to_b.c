/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   half_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 22:28:17 by nharra            #+#    #+#             */
/*   Updated: 2019/10/19 14:12:11 by nharra           ###   ########.fr       */
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
		if (ptr->tag < middle)
		{
			return (1);
		}
		--size;
		ptr = ptr->next;
	}
	return (0);
}

static void		take_rra(t_stack *a, t_stack *b,
				size_t to_a, size_t full_size)
{
	if (full_size == a->size + b->size)
		return ;
	while(to_a)
	{
		rev_rotate_op(a);
		ft_putstr("rra\n");
		--to_a;
	}
}

size_t			half_to_b(t_stack *a, t_stack *b, size_t size)
{
	int		middle;
	size_t	to_a;
	size_t	to_b;

	to_a = 0;
	to_b = 0;
	middle = find_middle(a, size);
	while (check_more(a, size--, middle))
	{
		if (a->beg->tag >= middle)
		{
			rotate_op(a);
			ft_putstr("ra\n");
			++to_a;
		}
		else
		{
			push_op(a, b);
			ft_putstr("pb\n");
			++to_b;
		}
	}
	take_rra(a, b, to_a, size + to_b + to_a);
	return(to_b);
}
