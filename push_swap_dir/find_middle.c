/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_middle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 11:40:38 by nharra            #+#    #+#             */
/*   Updated: 2019/10/02 14:32:16 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void			continue_pushsorttag(t_dlist **lst, t_dlist *side,
										int tag, t_dlist *ptr)
{
	if (tag > side->tag)
	{
		side->next = ptr;
		ptr->next = NULL;
		ptr->prev = side;
	}
	else
	{
		if (side->prev)
			side->prev->next = ptr;
		ptr->prev = side->prev;
		ptr->next = side;
		side->prev = ptr;
		if (side == *lst)
			*lst = ptr;
	}
}

static t_dlist		*ft_dlist_pushsorttag(t_dlist **lst, int tag)
{
	t_dlist		*ptr;
	t_dlist		*side;

	if (!(ptr = (t_dlist *)malloc(sizeof(*ptr))))
		return (NULL);
	ptr->tag = tag;
	ptr->content = NULL;
	if (*lst == NULL)
	{
		ptr->prev = NULL;
		ptr->next = NULL;
		*lst = ptr;
		return (*lst);
	}
	side = *lst;
	while ((side->tag < tag) && side->next)
		side = side->next;
	continue_pushsorttag(lst, side, tag, ptr);
	return (*lst);
}

int					find_middle(const t_dlist *beg, const t_dlist *end)
{
	t_dlist		*new;
	size_t		len;
	t_dlist		*ptr;
	int			tag;

	if (beg == end)
		return (beg->tag);
	new = NULL;
	len = 0;
	while (beg != end)
	{
		ft_dlist_pushsorttag(&new, beg->tag);
		++len;
		beg = beg->next;
	}
	ft_dlist_pushsorttag(&new, beg->tag);
	++len;
	ptr = new;
	len /= 2;
	while (len--)
		ptr = ptr->next;
	tag = ptr->tag;
	printf("tag = %d\n", tag);
	sleep(1);
	ft_dlist_simple_del(&new);
	return (tag);
}
