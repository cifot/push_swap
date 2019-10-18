/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_simple_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:59:53 by nharra            #+#    #+#             */
/*   Updated: 2019/10/18 13:24:15 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"
#include <stdio.h>

static void		sort_2a(t_stack *a)
{
	if (a->beg->tag > a->beg->next->tag)
	{
		ft_putstr("sa\n");
		swap_op(a);
	}
	if (a->size != 2)
	{
		ft_putstr("ra\n");
		ft_putstr("ra\n");
	}
	rotate_op(a);
	rotate_op(a);
}

static int		check_sort(t_stack *a, size_t size_a)
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

static void		sort_3a(t_stack *a)
{
	if (a->beg->tag > a->beg->next->next->tag
	&& a->beg->tag > a->beg->next->tag)
	{
		if (a->beg->next->tag > a->beg->next->next->tag)
			ft_putstr("pb\nsa\nra\nra\npa\nra\n");
		else
			ft_putstr("sa\nra\nsa\nra\nra\n");
	}
	else if (a->beg->next->tag > a->beg->next->next->tag
	&& a->beg->next->tag > a->beg->tag)
	{
		if (a->beg->tag > a->beg->next->next->tag)
			ft_putstr("pb\nsa\nra\npa\nra\nra\n");
		else
			ft_putstr("ra\nsa\nra\nra\n");
	}
	else
		ft_putstr("sa\nra\nra\nra\n");
	rotate_op(a);
	rotate_op(a);
	rotate_op(a);
}

int				check_simple_a(t_stack *a, size_t size_a)
{
	if (check_sort(a, size_a))
	{
		if (size_a != a->size)
			while (size_a)
			{
				ft_putstr("ra\n");
				rotate_op(a);
				--size_a;
			}
		return (1);
	}
	if (size_a > 3)
		return (0);
	if (size_a == 1)
	{
		ft_putstr("ra\n");
		rotate_op(a);
	}
	else if (size_a == 2)
		sort_2a(a);
	else if (size_a == 3)
		sort_3a(a);
	return (1);
}
