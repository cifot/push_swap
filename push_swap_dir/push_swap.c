/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:43:05 by nharra            #+#    #+#             */
/*   Updated: 2019/10/19 13:39:44 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"
#include "push_swap.h"

int				main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	if (argc == 1)
		return (1);
	a = ft_stack_new();
	b = ft_stack_new();
	if (make_input(argc, argv, a))
		ft_putstr("Error\n");
	else if (a->size != 0)
		sort_stack_a_b(a, b, a->size);
	ft_stack_del_link(&a);
	ft_stack_del_link(&b);
	return (1);
}
