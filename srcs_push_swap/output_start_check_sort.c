/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_start_check_sort.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:51:54 by nharra            #+#    #+#             */
/*   Updated: 2019/10/04 13:44:35 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void			check_is_sorted_first_b(t_stack *a, t_stack *b, int *n)
{
	int i;

	i = 0;
	if (*n > 1)
	{
		while (i < *n - 1)
		{
			if (b->data[b->n] < b->data[b->n - i - 1])
				break ;
			i++;
		}
		if (i == *n)
		{
			*n -= 1;
			ft_putendl("pa");
			stack_push(a, b, "pa");
			check_is_sorted_first_b(a, b, n);
		}
	}
}

void			check_is_sorted_first_a(t_stack *a, int *n)
{
	int i;
	int j;

	i = a->n - (*n) + 1;
	while (i < a->n)
	{
		j = i + 1;
		while (j <= a->n)
		{
			if (a->data[i] < a->data[j])
				break ;
			j++;
		}
		if (j > a->n)
			*n -= 1;
		else
			return ;
		i++;
	}
}
