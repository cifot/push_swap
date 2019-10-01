/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 12:38:04 by nharra            #+#    #+#             */
/*   Updated: 2019/10/01 13:42:52 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

void			op_pa(t_dlist **stack_a, t_dlist **stack_b)
{
	if (!stack_a || !stack_b || !(*stack_b))
		return ;
	if (*stack_a == NULL)
	{
		*stack_a = *stack_b;
		*stack_b = (*stack_b)->next;
		(*stack_a)->next = NULL;
		(*stack_a)->prev = NULL;
	}
	else
	{
		(*stack_a)->prev = *stack_b;
		*stack_b = (*stack_b)->next;
		(*stack_a)->prev->next = *stack_a;
		(*stack_a) = (*stack_a)->prev;
	}
}
