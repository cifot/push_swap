/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:51:50 by nharra            #+#    #+#             */
/*   Updated: 2019/10/04 13:44:13 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"

void	last_1a1b(t_stack *a, t_stack *b)
{
	ft_putendl("pa");
	stack_push(a, b, "pa");
	if (a->data[a->n] > a->data[a->n - 1])
	{
		ft_putendl("sa");
		stack_swap(a, b, "sa");
	}
}

void	last_2a1b(t_stack *a, t_stack *b)
{
	if (a->data[a->n] > a->data[a->n - 1])
	{
		ft_putendl("sa");
		stack_swap(a, b, "sa");
	}
	ft_putendl("pa");
	stack_push(a, b, "pa");
}

void	last_1a2b(t_stack *a, t_stack *b)
{
	if (b->data[b->n] < b->data[b->n - 1])
	{
		ft_putendl("sb");
		stack_swap(a, b, "sb");
	}
	ft_putendl("pa");
	stack_push(a, b, "pa");
	ft_putendl("pa");
	stack_push(a, b, "pa");
}

void	last_2a2b(t_stack *a, t_stack *b)
{
	if (a->data[a->n] > a->data[a->n - 1] &&
		b->data[b->n] < b->data[b->n - 1])
	{
		ft_putendl("ss");
		stack_swap(a, b, "ss");
	}
	else if (a->data[a->n] > a->data[a->n - 1])
	{
		ft_putendl("sa");
		stack_swap(a, b, "sa");
	}
	else if (b->data[b->n] < b->data[b->n - 1])
	{
		ft_putendl("sb");
		stack_swap(a, b, "sb");
	}
	ft_putendl("pa");
	stack_push(a, b, "pa");
	ft_putendl("pa");
	stack_push(a, b, "pa");
}
