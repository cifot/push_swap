/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:52:14 by nharra            #+#    #+#             */
/*   Updated: 2019/10/04 12:52:15 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"

static int		create_stacks(int argc, char **argv, t_stack *a)
{
	if (push_input(argc, argv, a) == -1)
		return (-1);
	return (1);
}

int				main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	long		len;

	if (argc == 1)
		return (1);
	len = check_size(argv, 1, argc);
	a = new_stack(len);
	b = new_stack(len);
	if (create_stacks(argc, argv, a) == -1)
		ft_putstr("Error\n");
	else
	{
		if (a->n != 0)
			push_swap_output_ra(a, b, a->n);
	}
	stack_delete(a);
	stack_delete(b);
	return (1);
}
