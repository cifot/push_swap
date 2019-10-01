/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_delone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:56:23 by nharra            #+#    #+#             */
/*   Updated: 2019/10/01 15:09:24 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include <stdlib.h>

void	ft_dlist_delone(t_dlist **lst, t_dlist *ptr, void (*del)(void *))
{
	if (ptr && lst && *lst)
	{
		if (ptr->prev)
			ptr->prev->next = ptr->next;
		if (ptr->next)
			ptr->next->prev = ptr->prev;
		if (*lst == ptr)
			*lst = ptr->next;
		del(ptr->content);
		free(ptr);
	}
}
