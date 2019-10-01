/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_pushtag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 11:55:53 by nharra            #+#    #+#             */
/*   Updated: 2019/10/01 15:08:30 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include <stdlib.h>

t_dlist			*ft_dlist_pushtag(t_dlist **lst, int tag)
{
	t_dlist		*ptr;
	t_dlist		*end;

	if (!lst || !(ptr = (t_dlist *)malloc(sizeof(*ptr))))
		return (NULL);
	ptr->tag = tag;
	ptr->next = NULL;
	ptr->content = NULL;
	if (*lst == NULL)
	{
		ptr->prev = NULL;
		*lst = ptr;
		return (*lst);
	}
	end = *lst;
	while (end->next)
		end = end->next;
	end->next = ptr;
	ptr->prev = end;
	return (*lst);
}
