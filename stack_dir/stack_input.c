/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:52:57 by nharra            #+#    #+#             */
/*   Updated: 2019/10/08 23:26:28 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		check_same(t_dlist *lst)
{
	t_dlist *ptr1;
	t_dlist *ptr2;

	ptr1 = lst;
	while(ptr1)
	{
		ptr2 = ptr1->next;
		while (ptr2)
		{
			if (ptr1->tag == ptr2->tag)
				return (-1);
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	return (1);
}

static int		check_num(char *str, t_dlist **ptr)
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
	ft_dlist_push_link(ptr, NULL, res);
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

static int		split(char *str, t_dlist **lst)
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
				if (check_num(words[i], lst) == -1)
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
	t_dlist	*ptr;

	ptr = NULL;
	i = argc - 1;
	while (i > 0)
	{
		if (split(argv[i], &ptr) == -1)
		{
			ft_dlist_del_link(&ptr);
			return (-1);
		}
		i--;
	}
	if (check_same(ptr) == -1)
	{
		ft_dlist_del_link(&ptr);
		return (-1);
	}
	stack->beg = ptr;
	stack->size = ft_dlist_len(ptr);
	return (1);
}
