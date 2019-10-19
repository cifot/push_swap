/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:48:30 by nharra            #+#    #+#             */
/*   Updated: 2019/10/18 23:46:49 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"
#include "push_swap.h"
#include <stdio.h>

void			sort_stack_b_a(t_stack *a, t_stack *b, size_t size)
{
	size_t size_b;
	size_t size_a;

	if (ft_dlist_is_tagsort(b->beg, 0) ||
		check_simple_b(b, size))
		return ;
	size_a = half_to_a(a, b, size);
	size_b = size - size_a;
	sort_stack_a_b(a, b, size_a);
	sort_stack_b_a(a, b, size_b);
}

void			sort_stack_a_b(t_stack *a, t_stack *b, size_t size)
{
	size_t size_b;
	size_t size_a;

	if (ft_dlist_is_tagsort(a->beg, 1) ||
		check_simple_a(a, size))
		return ;
	size_b = half_to_b(a, b, size);
	size_a = size - size_b;
	sort_stack_a_b(a, b, size_a);
	sort_stack_b_a(a, b, size_b);
}
