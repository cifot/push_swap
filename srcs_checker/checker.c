/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:51:04 by nharra            #+#    #+#             */
/*   Updated: 2019/10/04 13:49:05 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int		check_command2(t_stack *a, t_stack *b, char *line)
{
	if (stack_swap(a, b, line) == 0 &&
		stack_push(a, b, line) == 0 &&
		stack_rotate(a, b, line) == 0)
	{
		free(line);
		return (-1);
	}
	return (1);
}

static int		check_command(t_stack *a, t_stack *b)
{
	char	*line;
	int		count;

	count = 0;
	line = NULL;
	if (a->n == 0)
		return (1);
	while (get_next_line(0, &line) > 0 && line)
	{
		if (check_command2(a, b, line) == -1)
			return (-1);
		free(line);
		line = NULL;
		count++;
	}
	if (stack_is_sort(a) == -1 || b->n != 0)
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	return (1);
}

static int		create_stacks(int argc, char **argv, t_stack *a)
{
	if (push_input(argc, argv, a) == -1)
		return (-1);
	return (1);
}

int				main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	long		len;

	if (argc == 1)
		return (1);
	len = check_size(argv, 1, argc);
	a = new_stack(len);
	b = new_stack(len);
	if (create_stacks(argc, argv, a) == -1 ||
		check_command(a, b) == -1)
		ft_putstr("Error\n");
	stack_delete(a);
	stack_delete(b);
	return (1);
}
