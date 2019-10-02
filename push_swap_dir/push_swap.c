/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:05:48 by nharra            #+#    #+#             */
/*   Updated: 2019/10/02 18:30:03 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utilities.h"
#include <unistd.h>
#include <stdio.h>

void			print_stack(t_dlist *st)
{
	while (st)
	{
		printf("%d\n", st->tag);
		st = st->next;
	}
}

void			simpe_sort(t_dlist *beg, t_dlist *end)
{
	if (!beg || !end || beg == end)
		return ;
	if (beg->tag > end->tag)
	{
		write(1, "sa\n", 1);
		op_sa(&beg);
	}
}

void			quick_sort(t_dlist *first, t_dlist *end, t_dlist *second)
{
	int		middle;
	t_dlist	*ptr;

	if (!first || !end || first == end)
		return ;
	printf("stack a\n");
	print_stack(first);
	printf("stack b\n");
	if (ft_dlist_len(first, end) == 2)
	{
		simpe_sort(first, end);
		return ;
	}
	middle = find_middle(first, end);
	write(1, "pb\n", 3);
	while (first != end)
	{
		if (first->tag < middle)
		{
			write(1, "pb\n", 3);
			op_pa(&second, &first);
		}
		else
		{
			write(1, "ra\n", 3);
			op_ra(&first);
		}
	}
	ptr = first;
	printf("stack a\n");
	print_stack(first);
	printf("stack b\n");
	print_stack(second);
	while (second)
	{
		write(1, "pa\n", 3);
		op_pa(&first, &second);
	}
	quick_sort(first, ptr, second);
	quick_sort(ptr, first, second);
}

int				main(int argc, const char **argv)
{
	t_dlist		*stack_a;
	t_dlist		*stack_b;
	t_dlist		*end;

	stack_a = NULL;
	stack_b = NULL;
	if (argc != 2)
		return (0);
	if (init_stack(&stack_a, argv[1]) == -1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (stack_a->next == NULL)
		return (0);
	end = stack_a;
	while (end->next)
		end = end->next;

	quick_sort(stack_a, end, stack_b);
	return (0);
}
