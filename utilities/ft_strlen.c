/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:14:22 by nharra            #+#    #+#             */
/*   Updated: 2019/10/01 11:22:23 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

size_t		ft_strlen(const char *s)
{
	size_t size;

	size = 0;
	while (*s)
	{
		++s;
		++size;
	}
	return (size);
}
