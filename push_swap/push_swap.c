/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:05:48 by nharra            #+#    #+#             */
/*   Updated: 2019/10/01 17:55:26 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utilities.h"

int				main(int argc, const char **argv)
{
	t_dlist		*stack_a;
	t_dlist		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc != 2)
		return (0);
	if (init_stack(&stack_a, argv[1]) == -1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (stack_b != NULL || ft_dlist_is_sorted(stack_a))
	{
		if (check_r()
	}

	return (0);
}
