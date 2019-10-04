/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:52:31 by nharra            #+#    #+#             */
/*   Updated: 2019/10/04 13:57:13 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void			swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void			sort(int *left, int *right, int z)
{
	int		*ll;
	int		*rr;

	if (right - left <= 1)
		return ;
	z = *(left + (right - left) / 2);
	ll = left;
	rr = right - 1;
	while (ll <= rr)
	{
		while (*ll < z)
			ll++;
		while (*rr > z)
			rr--;
		if (ll <= rr)
		{
			swap(&ll[0], &rr[0]);
			ll++;
			rr--;
		}
	}
	if (left < rr)
		sort(left, rr + 1, 0);
	if (ll < right)
		sort(ll, right, 0);
}

int					quick_sort_array(t_stack *stack, int start, char c)
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
	sort(array, array + count, 0);
	i = 0;
	if (c == 'b' && count % 2 == 0)
		count--;
	middle = array[count / 2];
	free(array);
	return (middle);
}
