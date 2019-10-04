/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:52:42 by nharra            #+#    #+#             */
/*   Updated: 2019/10/04 20:32:37 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		is_max_than(t_stack *stack, int n)
{
	int i;

	i = 1;
	while (i <= stack->n)
	{
		if (n < stack->data[i])
			return (1);
		i++;
	}
	return (0);
}

int		is_min_than(t_stack *stack, int n)
{
	int i;

	i = 1;
	while (i <= stack->n)
	{
		if (n > stack->data[i])
			return (1);
		i++;
	}
	return (0);
}
