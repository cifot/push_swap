/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:48:30 by nharra            #+#    #+#             */
/*   Updated: 2019/10/21 00:53:00 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"
#include "push_swap.h"
#include <stdio.h>

static int		check_ascending_sort(t_stack *a, size_t size_a)
{
	t_dlist		*lst;

	if (!a || size_a < 2)
		return (1);
	lst = a->beg;
	while (lst->next && (size_a - 1))
	{
		if (lst->tag > lst->next->tag)
		{
			return (0);
		}
		--size_a;
		lst = lst->next;
	}
	return (1);
}

static int		check_descending_sort(t_stack *a, size_t size_a)
{
	t_dlist		*lst;

	if (!a || size_a < 2)
		return (1);
	lst = a->beg;
	while (lst->next && (size_a - 1))
	{
		if (lst->tag < lst->next->tag)
		{
			return (0);
		}
		--size_a;
		lst = lst->next;
	}
	return (1);
}

void			sort_stack_b_a(t_stack *a, t_stack *b, size_t size)
{
	size_t size_b;
	size_t size_a;

	if (check_descending_sort(b, size))
	{
		while(size)
		{
			ft_putstr("pa\n");
			push_op(b, a);
			--size;
		}
		return ;
	}
	if (check_simple_b(b, a, size))
		return ;
	size_a = half_to_a(a, b, size);
	size_b = size - size_a;
	sort_stack_a_b(a, b, size_a);
	sort_stack_b_a(a, b, size_b);
}

void			sort_stack_a_b(t_stack *a, t_stack *b, size_t size)
{
	size_t size_b;
	size_t size_a;

	if (check_ascending_sort(a, size) ||
		check_simple_a(a, size))
		return ;
	size_b = half_to_b(a, b, size);
	size_a = size - size_b;
	sort_stack_a_b(a, b, size_a);
	sort_stack_b_a(a, b, size_b);
}
