/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 13:43:10 by nharra            #+#    #+#             */
/*   Updated: 2019/10/01 14:56:59 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

void	op_sa(t_dlist **stack)
{
	t_dlist *second;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	second = (*stack)->next;
	if (second->next)
		second->next->prev = *stack;
	(*stack)->next = second->next;
	(*stack)->prev = second;
	second->next = (*stack);
	second->prev = NULL;
	*stack = second;
}

void	op_ss(t_dlist **stack_a, t_dlist **stack_b)
{
	op_sa(stack_a);
	op_sa(stack_b);
}
