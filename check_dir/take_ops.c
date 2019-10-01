/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 12:26:19 by nharra            #+#    #+#             */
/*   Updated: 2019/10/01 15:49:47 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>

static int		take_op(char *line, t_dlist **stack_a, t_dlist **stack_b)
{
	if (!strcmp(line, SA))
		op_sa(stack_a);
	else if (!strcmp(line, SB))
		op_sa(stack_b);
	else if (!strcmp(line, SS))
		op_ss(stack_a, stack_b);
	else if (!strcmp(line, PA))
		op_pa(stack_a, stack_b);
	else if (!strcmp(line, PB))
		op_pa(stack_b, stack_a);
	else if (!strcmp(line, RA))
		op_ra(stack_a);
	else if (!strcmp(line, RB))
		op_ra(stack_b);
	else if (!strcmp(line, RR))
		op_rr(stack_a, stack_b);
	else if (!strcmp(line, RRA))
		op_rra(stack_a);
	else if (!strcmp(line, RRB))
		op_rra(stack_b);
	else if (!strcmp(line, RRR))
		op_rrr(stack_a, stack_b);
	else
		return (-1);
	return (0);
}

int				take_ops(t_dlist **stack_a, t_dlist **stack_b)
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(1, &line)))
	{
		if (ret == -1 || (take_op(line, stack_a, stack_b) == -1))
		{
			ft_dlist_simple_del(stack_a);
			ft_dlist_simple_del(stack_b);
			free(line);
			return (-1);
		}
		free(line);
	}
	return (0);
}
