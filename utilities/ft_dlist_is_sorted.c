/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_is_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 14:11:41 by nharra            #+#    #+#             */
/*   Updated: 2019/10/01 15:04:47 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

int		ft_dlist_is_sorted(t_dlist *lst)
{
	if (!lst)
		return (0);
	lst = lst->next;
	while (lst)
	{
		if (lst->tag < lst->prev->tag)
			return (-1);
		lst = lst->next;
	}
	return (0);
}
