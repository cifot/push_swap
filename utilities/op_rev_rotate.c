/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 13:07:05 by nharra            #+#    #+#             */
/*   Updated: 2019/10/01 14:51:08 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

void			op_rra(t_dlist **stack_a)
{
	t_dlist	*ptr;

	if (!stack_a || !(*stack_a))
		return ;
	ptr = *stack_a;
	while (ptr->next)
		ptr = ptr->next;
	if (ptr == *stack_a)
		return ;
	ptr->next = *stack_a;
	ptr->prev->next = NULL;
	ptr->prev = NULL;
	(*stack_a)->prev = ptr;
	*stack_a = ptr;
}

void			op_rrr(t_dlist **stack_a, t_dlist **stack_b)
{
	op_rra(stack_a);
	op_rra(stack_b);
}
