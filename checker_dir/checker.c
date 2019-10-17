/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:51:04 by nharra            #+#    #+#             */
/*   Updated: 2019/10/17 19:22:00 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h>

static int		check_command_continue(t_stack *a, t_stack *b, char *line)
{
	if (check_swap(a, b, line) &&
		check_push(a, b, line) &&
		check_rot(a, b, line))
	{
		free(line);
		return (-1);
	}
	return (1);
}


static int		check_command(t_stack *a, t_stack *b)
{
	char		*line;
	int			count;

	count = 0;
	line = NULL;
	while (get_next_line(0, &line) > 0 && line)
	{
		if (check_command_continue(a, b, line) == -1)
			return (-1);
		free(line);
		line = NULL;
		count++;
	}
	for(t_dlist *ptr = a->beg; ptr->next != NULL; ptr = ptr->next)
	{
		if (ptr->tag > ptr->next->tag)
		{
			ft_putnbr(ptr->tag);
			ft_putstr("\n");
		}
	}
	if (ft_dlist_is_tagsort(a->beg, 1) == 0 || b->size != 0)
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	return (1);
}

int				main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	if (argc == 1)
		return (1);
	a = ft_stack_new();
	b = ft_stack_new();
	if (make_input(argc, argv, a))
	{
		ft_putstr("Error\n");
	}
	else if (a->size != 0)
	{
		if (check_command(a, b) == -1)
			ft_putstr("Error\n");
	}
	else
		ft_putstr("\n");
	ft_stack_del_link(&a);
	ft_stack_del_link(&b);
	return (1);
}
