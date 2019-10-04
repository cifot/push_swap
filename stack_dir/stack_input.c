/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:52:57 by nharra            #+#    #+#             */
/*   Updated: 2019/10/04 20:32:34 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int		check_same(t_stack *stack)
{
	int	j;
	int	i;

	j = 1;
	while (j <= (int)(stack->n))
	{
		i = j + 1;
		while (i <= (int)(stack->n))
		{
			if ((stack->data)[i] == (stack->data)[j])
				return (-1);
			i++;
		}
		j++;
	}
	return (1);
}

static int		check_num(char *str, t_stack *stack)
{
	int		n;
	long	res;

	n = 0;
	res = ft_atol(str);
	while (((*str) >= 2 && (*str) <= 32) && (*str) != 27)
		str++;
	if (((*str) == '+' || (*str) == '-') && ft_isdigit((str[1])) == 1)
		str++;
	while ((*str) != '\0')
	{
		if (ft_isdigit((*str)) == 0)
			return (-1);
		else
			n++;
		str++;
	}
	if (n > 11 || res > 2147483647 || res < -2147483648)
		return (-1);
	push(stack, res);
	return (1);
}

static void		delete_split(char **words)
{
	int i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}

static int		split(char *str, t_stack *stack)
{
	char	**words;
	int		len;
	int		i;

	len = 0;
	if ((words = ft_strsplit(str, ' ')))
	{
		while (words[len])
			len++;
		i = len - 1;
		while (i >= 0)
		{
			if (ft_strlen(words[i]) > 0)
				if (check_num(words[i], stack) == -1)
				{
					delete_split(words);
					return (-1);
				}
			i--;
		}
		delete_split(words);
	}
	else
		return (-1);
	return (1);
}

int				push_input(int argc, char **argv, t_stack *stack)
{
	int		i;

	i = argc - 1;
	while (i > 0)
	{
		if (split(argv[i], stack) == -1)
			return (-1);
		i--;
	}
	if (check_same(stack) == -1)
		return (-1);
	return (1);
}
