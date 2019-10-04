/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_middle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:52:31 by nharra            #+#    #+#             */
/*   Updated: 2019/10/04 21:08:53 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void			sort(int *left, int *right)
{
	int		i;
	int		j;
	int		k;

	if (right - left <= 1)
		return ;
	i = 0;
	while(left + i < right)
	{
		j = i;
		k = i;
		while (left + j < right)
		{
			if (left[j] < left[k])
				k = j;
			++j;
		}
		j = left[k];
		left[k] = left[i];
		left[i] = j;
		++i;
	}
}

int					find_middle_array(t_stack *stack, int start, char c)
{
	int		*array;
	int		count;
	int		i;
	int		middle;

	i = 0;
	count = stack->n - start + 1;
	if (!(array = ft_memalloc(count * sizeof(int))))
		return (-1);
	while (i < count)
	{
		array[i] = stack->data[start + i];
		i++;
	}
	sort(array, array + count);
	i = 0;
	if (c == 'b' && count % 2 == 0)
		count--;
	middle = array[count / 2];
	free(array);
	return (middle);
}
