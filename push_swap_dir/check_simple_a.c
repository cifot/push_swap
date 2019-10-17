/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_simple_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:59:53 by nharra            #+#    #+#             */
/*   Updated: 2019/10/17 17:48:55 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"
#include <stdio.h>

void	sort_2a(t_stack *a)
{
	if (a->beg->tag > a->beg->next->tag)
	{
		ft_putstr("sa\n");
		swap_op(a);
	}
	ft_putstr("ra\n");
	ft_putstr("ra\n");
	rotate_op(a);
	rotate_op(a);
}

int		check_sort(t_stack *a, size_t size_a)
{
	t_dlist		*lst;

	if (!a || !(a->beg) || size_a < 2)
		return 1;
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

static void all_rotate(t_stack *a, size_t size_a)
{
	while(size_a)
	{
		ft_putstr("ra\n");
		rotate_op(a);
		--size_a;
	}
}

int		check_simple_a(t_stack *a, size_t size_a)
{
	if (check_sort(a, size_a))
	{
		all_rotate(a, size_a);
		return (1);
	}
	if (size_a > 2)
		return (0);
	if (size_a == 1)
	{
		ft_putstr("ra\n");
		rotate_op(a);
	}
	else if (size_a == 2)
		sort_2a(a);
	return (1);
}
