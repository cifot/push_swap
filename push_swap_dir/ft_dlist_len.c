/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:33:06 by nharra            #+#    #+#             */
/*   Updated: 2019/10/02 14:48:18 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

size_t	ft_dlist_len(t_dlist *beg, t_dlist *end)
{
	size_t len;

	len = 0;
	while (beg != end)
	{
		++len;
		beg = beg->next;
	}
	return (len + 1);
}
