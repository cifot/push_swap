/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:48:30 by nharra            #+#    #+#             */
/*   Updated: 2019/11/26 02:07:56 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"
#include "push_swap.h"

void			sort_stack(t_stack *a, t_stack *b)
{
	t_op_cost	cost;

	drop_to_b(a, b);
	while(b->size != 0)
	{
		find_min_cost(&cost, a, b);
		min_cost_to_a(&cost, a, b);
	}
}
