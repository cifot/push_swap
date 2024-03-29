/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_simple_del.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 23:28:40 by nharra            #+#    #+#             */
/*   Updated: 2019/10/15 23:31:25 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stack_simple_del(t_stack **st)
{
	if (st && *st)
	{
		ft_dlist_simple_del(&((*st)->beg));
		free(*st);
		*st = NULL;
	}
}
