/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_simple_delone.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:04:25 by nharra            #+#    #+#             */
/*   Updated: 2019/10/01 11:54:32 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include <stdlib.h>

void	ft_dlist_simple_delone(t_dlist **lst, t_dlist *ptr)
{
	ft_dlist_delone(lst, ptr, free);
}
