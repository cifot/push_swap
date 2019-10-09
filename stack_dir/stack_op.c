/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:45:37 by nharra            #+#    #+#             */
/*   Updated: 2019/10/08 21:29:26 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push_op(t_stack *from, t_stack *to)
{
	int tag;

	if (!from || !(from->beg))
		return ;
	tag = from->beg->tag;
	ft_stack_pop(from);
	ft_stack_push_link(to, NULL, tag);
}

void	rotate_op(t_stack *stack)
{
	t_dlist *end;

	if (!stack || !(stack->beg) || !(stack->beg->next))
		return ;
	end = stack->beg;
	while (end->next)
		end = end->next;
	end->next = stack->beg;
	stack->beg->prev = end;
	stack->beg = stack->beg->next;
	stack->beg->prev->next = NULL;
	stack->beg->prev = NULL;
}

void	rev_rotate_op(t_stack *stack)
{
	t_dlist *end;

	if (!stack || !(stack->beg) || !(stack->beg->next))
		return ;
	end = stack->beg;
	while (end->next)
		end = end->next;
	end->next = stack->beg;
	end->prev->next = NULL;
	end->prev = NULL;
	stack->beg->prev = end;
	stack->beg = end;
}

void	swap_op(t_stack *stack)
{
	t_dlist *ptr;

	if (!stack || !(stack->beg) || !(stack->beg->next))
		return ;
	ptr = stack->beg->next;
	stack->beg->prev = ptr;
	stack->beg->next = ptr->next;
	ptr->next = stack->beg;
	ptr->prev = NULL;
	stack->beg = ptr;
}
