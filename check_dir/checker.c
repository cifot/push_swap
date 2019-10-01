/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 11:04:27 by nharra            #+#    #+#             */
/*   Updated: 2019/10/01 16:56:32 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <unistd.h>

static void		print_ok(t_dlist **stack_a, t_dlist **stack_b)
{
	ft_dlist_simple_del(stack_a);
	ft_dlist_simple_del(stack_b);
	write(1, "OK\n", 3);
}

static void		print_ko(t_dlist **stack_a, t_dlist **stack_b)
{
	ft_dlist_simple_del(stack_a);
	ft_dlist_simple_del(stack_b);
	write(1, "KO\n", 3);
}

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
	if (take_ops(&stack_a, &stack_b) == -1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (stack_b == NULL && !ft_dlist_is_sorted(stack_a))
		print_ok(&stack_a, &stack_b);
	else
		print_ko(&stack_a, &stack_b);
	return (0);
}
