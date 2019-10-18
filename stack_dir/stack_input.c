/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:52:57 by nharra            #+#    #+#             */
/*   Updated: 2019/10/18 13:27:59 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"
#include <stdio.h>

static int		check_same(t_stack *st)
{
	t_dlist *ptr1;
	t_dlist *ptr2;

	ptr1 = st->beg;
	while (ptr1)
	{
		ptr2 = ptr1->next;
		while (ptr2)
		{
			if (ptr1->tag == ptr2->tag)
				return (1);
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	return (0);
}

static int		add_num(char *str, t_stack *st)
{
	long		unswer;
	int			flag_find;
	int			flag;

	flag_find = 0;
	flag = 1;
	unswer = 0;
	while (*str == ' ')
		++str;
	if (*str == '-' || *str == '+')
		if (*(str++) + (flag_find = 2) - 2 == '-')
			flag = -1;
	while (*str <= '9' && *str >= '0')
	{
		unswer = unswer * 10 + flag * (*str - '0');
		flag_find = 1;
		if (unswer > INT_MAX || unswer < INT_MIN)
			return (-1);
		++str;
	}
	if (flag_find == 2 || (*str != '\0'))
		return (-1);
	else if (flag_find == 1)
		ft_stack_push_link(st, NULL, unswer);
	return (0);
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

static int		add_nums(char *str, t_stack *st)
{
	char		**words;
	int			i;
	t_stack		*tmp;

	tmp = ft_stack_new();
	if (!(words = ft_strsplit(str, ' ')))
		return (-1);
	i = 0;
	while (words[i])
	{
		if (add_num(words[i], tmp) == -1)
		{
			ft_stack_del_link(&tmp);
			delete_split(words);
			return (-1);
		}
		++i;
	}
	while (tmp->size)
		push_op(tmp, st);
	ft_stack_del_link(&tmp);
	delete_split(words);
	return (0);
}

int				make_input(int argc, char **argv, t_stack *stack)
{
	int		i;

	i = argc - 1;
	while (i > 0)
	{
		if (add_nums(argv[i], stack) == -1)
			return (-1);
		--i;
	}
	if (check_same(stack))
		return (-1);
	return (0);
}
