/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 19:28:42 by nharra            #+#    #+#             */
/*   Updated: 2019/10/01 11:23:03 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char *buf;

	if (!(buf = (char *)malloc(size)))
		return (NULL);
	ft_bzero(buf, size);
	return (buf);
}
