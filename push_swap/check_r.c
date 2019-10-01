/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:53:57 by nharra            #+#    #+#             */
/*   Updated: 2019/10/01 17:15:23 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_ss

int		check_same(t_dlist **st_a, t_dlist **st_b)
{
	if (!(*st_a) || !((*st_a)->next) || !(*st_b) || !((*st_b)->next))
		return (0);
	if (((*st_a)->tag > (*st_a)->next->tag)
		&& ((*st_b)->tag < (*st_b)->next->tag))
	{
		op_ss(st_a, st_b);
		write(1, "ss\n", 3);
		return (1);
	}
	if (((*st_a)->tag > (*st_a)->next->tag)
		&& ((*st_b)->tag < (*st_b)->next->tag))
	{
		op_ss(st_a, st_b);
		write(1, "ss\n", 3);
		return (1);
	}
}
