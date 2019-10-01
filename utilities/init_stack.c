/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 11:38:31 by nharra            #+#    #+#             */
/*   Updated: 2019/10/01 16:05:27 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		init_stack(t_dlist **stack, const char *numbers)
{
	while (*numbers)
	{
		ft_dlist_pushtag(stack, ft_atol(&numbers));
		if (*(numbers) == ' ' || *(numbers) == '\0')
			continue;
		ft_dlist_simple_del(stack);
		return (-1);
	}
	return (0);
}

