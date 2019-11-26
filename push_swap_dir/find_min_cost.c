/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 21:19:44 by nharra            #+#    #+#             */
/*   Updated: 2019/11/26 02:05:38 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"
#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

static t_dlist	*last(t_dlist *lst)
{
	while(lst->next)
		lst = lst->next;
	return (lst);
}

static void		calculate_cost(t_op_cost *cost)
{
	size_t	way[COUNT_WAY];
	int		i_min;
	int		i;

	way[RA_RB] = cost->ra > cost->rb ? cost->ra : cost->rb;
	way[RRA_RRB] = cost->rra > cost->rrb ? cost->rra : cost->rrb;
	way[RA_RRB] = cost->ra + cost->rrb;
	way[RRA_RB] = cost->rra + cost->rb;
	i_min = 0;
	i = 1;
	while(i < COUNT_WAY)
	{
		if (way[i] < way[i_min])
			i_min = i;
		++i;
	}
	cost->min_cost = way[i_min];
	cost->way = i_min;
}

static void		check_cost(int value, t_op_cost *cost, t_stack *a)
{
	t_dlist		*ptr_a;

	ptr_a = a->beg;
	if (value > ptr_a->tag)
	{
		cost->rra = 1;
		ptr_a = last(ptr_a);
		while(ptr_a->tag < value)
		{
			ptr_a = ptr_a->prev;
			cost->rra += 1;
		}
		cost->ra = a->size - cost->rra;
	}
	else
	{
		cost->ra = 0;
		while(ptr_a->tag > value)
		{
			ptr_a = ptr_a->next;
			cost->rra += 1;
		}
		cost->rra = a->size - cost->ra;
	}
	calculate_cost(cost);
}

void			find_min_cost(t_op_cost *cost, t_stack *a, t_stack *b)
{
	t_dlist		*ptr_b;
	size_t		i;
	t_op_cost	tmp;

	cost->min_cost = ULONG_MAX;
	ptr_b = b->beg;
	i = 0;
	while(i < b->size)
	{
		tmp.rb = i;
		tmp.rrb = b->size - i;
		check_cost(ptr_b->tag, &tmp, a);
		if (tmp.min_cost < cost->min_cost)
			ft_memcpy(cost, &tmp, sizeof(tmp));
		++i;
		ptr_b = ptr_b->next;
	}
}
