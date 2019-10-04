/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:53:02 by nharra            #+#    #+#             */
/*   Updated: 2019/10/04 13:45:40 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack			*new_stack(long max_size)
{
	t_stack		*stack;

	if (!(stack = (t_stack*)ft_memalloc(sizeof(t_stack))))
		return (NULL);
	if (!(stack->data = (int*)ft_memalloc(sizeof(int) * (max_size + 1))))
	{
		free(stack);
		return (NULL);
	}
	ft_memset(stack->data, 0, sizeof(int) * (max_size + 1));
	stack->data[0] = 0;
	stack->max_size = max_size;
	stack->n = 0;
	return (stack);
}

long			check_size(char **argv, int start, int argc)
{
	int		i;
	char	**words;
	long	len;

	len = 0;
	while (start < argc)
	{
		i = 0;
		if ((words = ft_strsplit(argv[start], ' ')))
		{
			while (words[i])
				i++;
			len += i;
			while (i >= 0)
			{
				free(words[i]);
				i--;
			}
			free(words);
		}
		else
			return (-1);
		start++;
	}
	return (len);
}

int				push(t_stack *stack, int n)
{
	stack->n += 1;
	stack->data[stack->n] = n;
	return (1);
}

int				pop(t_stack *stack)
{
	int n;

	n = stack->data[stack->n];
	stack->n -= 1;
	return (n);
}

void			stack_delete(t_stack *stack)
{
	free(stack->data);
	free(stack);
}
