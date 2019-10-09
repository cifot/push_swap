/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:27:35 by nharra            #+#    #+#             */
/*   Updated: 2019/10/08 22:53:43 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		check_swap(t_stack *a, t_stack *b, char *line)
{
	if (!line)
		return (-1);
	if (!ft_strcmp(line, "sa"))
		swap_op(a);
	else if (!ft_strcmp(line, "sb"))
		swap_op(b);
	else if (!ft_strcmp(line, "ss"))
	{
		swap_op(a);
		swap_op(b);
	}
	else
		return (-1);
	return (0);
}

int		check_push(t_stack *a, t_stack *b, char *line)
{
	if (!line)
		return (-1);
	if (!ft_strcmp(line, "pa"))
		push_op(b, a);
	else if (!ft_strcmp(line, "pb"))
		push_op(a, b);
	else
		return (-1);
	return (0);
}

int		check_rot(t_stack *a, t_stack *b, char *line)
{
	if (!line)
		return (-1);
	if (!ft_strcmp(line, "ra"))
		rotate_op(a);
	else if (!ft_strcmp(line, "rb"))
		rotate_op(b);
	else if (!ft_strcmp(line, "rr"))
	{
		rotate_op(a);
		rotate_op(b);
	}
	else if (!ft_strcmp(line, "rrb"))
		rev_rotate_op(b);
	else if (!ft_strcmp(line, "rra"))
		rev_rotate_op(a);
	else if (!ft_strcmp(line, "rrr"))
	{
		rev_rotate_op(a);
		rev_rotate_op(b);
	}
	else
		return (-1);
	return (0);
}
