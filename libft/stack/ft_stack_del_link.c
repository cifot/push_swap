/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_del_link.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 21:04:03 by nharra            #+#    #+#             */
/*   Updated: 2019/10/15 23:27:38 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stack_del_link(t_stack **st)
{
	if (st && *st)
	{
		ft_dlist_del_link(&((*st)->beg));
		free(*st);
	}
}
