/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:02:38 by nharra            #+#    #+#             */
/*   Updated: 2019/10/01 11:22:30 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*save;
	size_t	i;

	i = 0;
	save = dest;
	while (src[i])
	{
		*dest = src[i];
		++dest;
		++i;
	}
	*dest = '\0';
	return (save);
}
