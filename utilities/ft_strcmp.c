/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 16:14:04 by nharra            #+#    #+#             */
/*   Updated: 2019/10/01 11:22:34 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include <stdlib.h>

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			break ;
		++i;
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
