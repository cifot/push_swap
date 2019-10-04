/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:52:51 by nharra            #+#    #+#             */
/*   Updated: 2019/10/04 13:47:19 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int					contains_less_mid(t_stack *stack, int middle)
{
	int i;

	i = 1;
	while (i <= stack->n)
	{
		if ((int)(stack->data[i]) < middle)
			return (1);
		i++;
	}
	return (0);
}

int					stack_is_sort(t_stack *stack)
{
	int i;

	i = 2;
	while (i <= (int)(stack->n))
	{
		if (stack->data[i - 1] < stack->data[i])
			return (-1);
		i++;
	}
	return (1);
}

int					stack_is_backsort(t_stack *stack, int start)
{
	int i;

	i = start + 2;
	while (i <= (int)(stack->n))
	{
		if (stack->data[i - 1] > stack->data[i])
			return (-1);
		i++;
	}
	return (1);
}
