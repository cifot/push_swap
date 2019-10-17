/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_middle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:49:57 by nharra            #+#    #+#             */
/*   Updated: 2019/10/17 12:50:13 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

static void		sort_arr(int *buf, size_t size)
{
	size_t	min;
	size_t	i;
	size_t	j;
	int		tmp;

	i = 0;
	while(i + 1 < size)
	{
		j = i + 1;
		min = i;
		while (j < size)
		{
			if (buf[j] < buf[min])
				min = j;
			++j;
		}
		if (min != i)
		{
			tmp = buf[i];
			buf[i] = buf[min];
			buf[min] = tmp;
		}
		++i;
	}
}

int				find_middle(t_stack *a, size_t count)
{
	size_t		i;
	int			*arr;
	t_dlist		*ptr;
	int			middle;

	i = 0;
	if (!(arr = (int *)malloc(sizeof(*arr) * count)))
		exit(0);
	ptr = a->beg;
	while (i < count)
	{
		arr[i] = ptr->tag;
		ptr = ptr->next;
		++i;
	}
	sort_arr(arr, count);
	middle = arr[count / 2];
	free(arr);
	return (middle);
}
