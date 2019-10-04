/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:51:44 by nharra            #+#    #+#             */
/*   Updated: 2019/10/04 13:48:06 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"

static void			start_back(t_stack *a, t_stack *b, int start)
{
	while (start != 0)
	{
		ft_putendl("rrb");
		stack_rotate(a, b, "rrb");
		start--;
	}
}

static int			check_last_iter_b(t_stack *a, t_stack *b,
					t_count count, int start)
{
	if (count.b != b->n)
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

static int			check_fst_iter_b(t_stack *a, t_stack *b, int n)
{
	int i;

	i = 0;
	if (stack_is_backsort(b, b->n - n) == 1)
	{
		while (i < n)
		{
			ft_putendl("pa");
			stack_push(a, b, "pa");
			i++;
		}
	}
	else if (n == 1)
		last_1b(a, b);
	else if (n == 2)
		last_2b(a, b);
	else if (n == 3)
		last_3b(a, b);
	else
		return (-1);
	return (1);
}

static int			push_swap_output_rb2(t_stack *a, t_stack *b,
					t_count *count, int n)
{
	int		middle;
	int		i;

	i = 0;
	middle = quick_sort_array(b, b->n - n + 1, 'b');
	while (i < n && is_max_than(b, middle) == 1)
	{
		if (middle < b->data[b->n])
		{
			ft_putendl("pa");
			stack_push(a, b, "pa");
			count->a += 1;
		}
		else
		{
			ft_putendl("rb");
			stack_rotate(a, b, "rb");
		}
		i++;
	}
	return (i);
}

void				push_swap_output_rb(t_stack *a, t_stack *b, int n)
{
	int		i;
	t_count	count;
	int		ca;

	check_is_sorted_first_b(a, b, &n);
	if ((ca = check_fst_iter_b(a, b, n)) > 0)
		return ;
	count.a = 0;
	i = push_swap_output_rb2(a, b, &count, n);
	count.b = n - count.a;
	if (check_last_iter_b(a, b, count, i - count.a) == 0)
	{
		push_swap_output_ra(a, b, count.a);
		if (b->n != 0)
			push_swap_output_rb(a, b, count.b);
	}
}
