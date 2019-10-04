/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_a_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:51:29 by nharra            #+#    #+#             */
/*   Updated: 2019/10/04 12:51:31 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"

void			last_2a(t_stack *a, t_stack *b)
{
	if (a->data[a->n] > a->data[a->n - 1])
	{
		ft_putendl("sa");
		stack_swap(a, b, "sa");
	}
}

static void		last_3a_dop(t_stack *a, t_stack *b)
{
	ft_putendl("sa");
	stack_swap(a, b, "sa");
	ft_putendl("ra");
	stack_rotate(a, b, "ra");
	ft_putendl("sa");
	stack_swap(a, b, "sa");
	ft_putendl("rra");
	stack_rotate(a, b, "rra");
	if (a->data[a->n] > a->data[a->n - 1])
		last_2a(a, b);
}

static void		last_3a_dop2(t_stack *a, t_stack *b)
{
	ft_putendl("ra");
	stack_rotate(a, b, "ra");
	ft_putendl("sa");
	stack_swap(a, b, "sa");
	ft_putendl("rra");
	stack_rotate(a, b, "rra");
	if (a->data[a->n] > a->data[a->n - 1])
		last_2a(a, b);
}

static void		last_3a_dop3(t_stack *a, t_stack *b)
{
	ft_putendl("rra");
	stack_rotate(a, b, "rra");
	if (a->data[a->n] > a->data[a->n - 1])
		last_2a(a, b);
}

void			last_3a(t_stack *a, t_stack *b)
{
	if (a->data[a->n - 2] > a->data[a->n - 1]
		&& a->data[a->n - 2] > a->data[a->n])
	{
		if (a->data[a->n] > a->data[a->n - 1])
			last_2a(a, b);
	}
	else if (a->data[a->n - 1] > a->data[a->n] &&
			a->data[a->n - 1] > a->data[a->n - 2] && a->n != 3)
		last_3a_dop2(a, b);
	else if (a->data[a->n - 1] > a->data[a->n] &&
			a->data[a->n - 1] > a->data[a->n - 2] && a->n == 3)
		last_3a_dop3(a, b);
	else if (a->data[a->n] > a->data[a->n - 1] &&
			a->data[a->n] > a->data[a->n - 2] && a->n != 3)
		last_3a_dop(a, b);
	else if (a->data[a->n] > a->data[a->n - 1]
		&& a->data[a->n] > a->data[a->n - 2] && a->n == 3)
	{
		ft_putendl("ra");
		stack_rotate(a, b, "ra");
		if (a->data[a->n] > a->data[a->n - 1])
			last_2a(a, b);
	}
}
