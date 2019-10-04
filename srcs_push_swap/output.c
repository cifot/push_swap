/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:52:09 by nharra            #+#    #+#             */
/*   Updated: 2019/10/04 12:52:10 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"

static void		start_back(t_stack *a, t_stack *b, int start)
{
	while (start != 0)
	{
		ft_putendl("rra");
		stack_rotate(a, b, "rra");
		start--;
	}
}

static int		check_last_iter(t_stack *a, t_stack *b,
				t_count count, int start)
{
	if (count.a != a->n)
		start_back(a, b, start);
	if (count.a == 1 && count.b == 1)
	{
		last_1a1b(a, b);
		return (1);
	}
	if (count.a == 2 && count.b == 1)
	{
		last_2a1b(a, b);
		return (1);
	}
	if (count.a == 1 && count.b == 2)
	{
		last_1a2b(a, b);
		return (1);
	}
	if (count.a == 2 && count.b == 2)
	{
		last_2a2b(a, b);
		return (1);
	}
	return (0);
}

static int		check_fst_iter_a(t_stack *a, t_stack *b, int n)
{
	if (stack_is_sort(a) == 1)
		return (1);
	if (n == 1)
		return (1);
	if (n == 2)
	{
		last_2a(a, b);
		return (1);
	}
	if (n == 3)
	{
		last_3a(a, b);
		return (1);
	}
	return (-1);
}

static int		push_swap_output_ra2(t_stack *a, t_stack *b,
									t_count *count, int n)
{
	int		i;
	int		middle;

	i = 0;
	middle = quick_sort_array(a, a->n - n + 1, 'a');
	while (i < n && is_min_than(a, middle) == 1)
	{
		if (stack_is_sort(a) == 1 && b->n == 0)
			break ;
		if (middle > a->data[a->n])
		{
			ft_putendl("pb");
			stack_push(a, b, "pb");
			count->b += 1;
		}
		else
		{
			ft_putendl("ra");
			stack_rotate(a, b, "ra");
		}
		i++;
	}
	return (i);
}

void			push_swap_output_ra(t_stack *a, t_stack *b, int n)
{
	int		i;
	t_count	count;

	check_is_sorted_first_a(a, &n);
	if (check_fst_iter_a(a, b, n) == 1)
		return ;
	count.b = 0;
	i = push_swap_output_ra2(a, b, &count, n);
	count.a = n - count.b;
	if (check_last_iter(a, b, count, i - count.b) == 0)
	{
		push_swap_output_ra(a, b, count.a);
		if (b->n != 0)
			push_swap_output_rb(a, b, count.b);
	}
}
