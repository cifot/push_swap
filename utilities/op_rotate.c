/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 12:48:51 by nharra            #+#    #+#             */
/*   Updated: 2019/10/01 13:42:00 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

void			op_ra(t_dlist **stack_a)
{
	t_dlist	*ptr;

	if (!stack_a || !(*stack_a))
		return ;
	ptr = *stack_a;
	while (ptr->next)
		ptr = ptr->next;
	if (ptr == *stack_a)
		return ;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev->next = NULL;
	(*stack_a)->prev->prev = ptr;
	ptr->next = (*stack_a)->prev;
	(*stack_a)->prev = NULL;
}

void			op_rr(t_dlist **stack_a, t_dlist **stack_b)
{
	op_ra(stack_a);
	op_ra(stack_b);
}
