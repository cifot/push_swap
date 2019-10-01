/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 18:11:08 by nharra            #+#    #+#             */
/*   Updated: 2019/10/01 11:22:47 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

char	*ft_strcat(char *dest, const char *src)
{
	char	*s;
	size_t	i;

	i = 0;
	s = dest;
	while (*s)
		++s;
	while (src[i])
	{
		*s = src[i];
		++s;
		++i;
	}
	*s = '\0';
	return (dest);
}
