/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:52:36 by nharra            #+#    #+#             */
/*   Updated: 2019/10/04 12:52:37 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int				stack_swap(t_stack *a, t_stack *b, char *command)
{
	int temp;

	if ((ft_strcmp("sa", command) == 0 || ft_strcmp("ss", command) == 0)
		&& a->n > 1)
	{
		temp = a->data[a->n];
		a->data[a->n] = a->data[a->n - 1];
		a->data[a->n - 1] = temp;
	}
	if ((ft_strcmp("sb", command) == 0 || ft_strcmp("ss", command) == 0)
		&& b->n > 1)
	{
		temp = b->data[b->n];
		b->data[b->n] = b->data[b->n - 1];
		b->data[b->n - 1] = temp;
	}
	if (ft_strcmp("sb", command) == 0 || ft_strcmp("ss", command) == 0
		|| ft_strcmp("sa", command) == 0)
		return (1);
	return (0);
}

int				stack_push(t_stack *a, t_stack *b, char *command)
{
	int temp;

	if (ft_strcmp("pa", command) == 0)
	{
		if (b->n < 1)
			return (1);
		temp = pop(b);
		push(a, temp);
		return (1);
	}
	if (ft_strcmp("pb", command) == 0)
	{
		if (a->n < 1)
			return (1);
		temp = pop(a);
		push(b, temp);
		return (1);
	}
	return (0);
}

static void		rotate(t_stack *a)
{
	int temp;
	int i;

	temp = a->data[a->n];
	i = a->n;
	while (i > 1)
	{
		a->data[i] = a->data[i - 1];
		i--;
	}
	if (i == 1)
		a->data[i] = temp;
}

static void		reverse_rotate(t_stack *a)
{
	int temp;
	int i;

	temp = a->data[1];
	i = 1;
	while (i < a->n)
	{
		a->data[i] = a->data[i + 1];
		i++;
	}
	if (i == a->n)
		a->data[i] = temp;
}

int				stack_rotate(t_stack *a, t_stack *b, char *command)
{
	if ((ft_strcmp("ra", command) == 0))
		rotate(a);
	else if ((ft_strcmp("rb", command) == 0))
		rotate(b);
	else if ((ft_strcmp("rr", command) == 0))
	{
		rotate(a);
		rotate(b);
	}
	else if ((ft_strcmp("rra", command) == 0))
		reverse_rotate(a);
	else if ((ft_strcmp("rrb", command) == 0))
		reverse_rotate(b);
	else if ((ft_strcmp("rrr", command) == 0))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else
		return (0);
	return (1);
}
