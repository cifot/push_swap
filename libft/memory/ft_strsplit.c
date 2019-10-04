/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 08:48:08 by nharra            #+#    #+#             */
/*   Updated: 2019/10/04 15:40:05 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_words(const char *str, char del)
{
	size_t size;

	size = 0;
	while (*str)
	{
		while (*str == del)
			++str;
		if (*str)
		{
			while ((*str != del) && *str)
				++str;
			++size;
		}
	}
	return (size);
}

static size_t	size_word(const char *str, char del)
{
	size_t size;

	size = 0;
	while (*str == del)
		++str;
	while ((*str != del) && *str)
	{
		++str;
		++size;
	}
	return (size);
}

static void		ft_free(char ***str, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free((*str)[j]);
		(*str)[j] = NULL;
	}
	free(*str);
	*str = NULL;
}

static void		ft_make_str(char const **str, int del, char *answer)
{
	size_t j;

	j = 0;
	while (**str == del)
		++(*str);
	while ((**str != del) && **str)
		answer[j++] = *((*str)++);
	answer[j] = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**answer;
	size_t	count;
	size_t	i;
	size_t	len_word;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	if (!(answer = (char**)malloc(sizeof(*answer) * (count + 1))))
		return (NULL);
	i = 0;
	while (i < count)
	{
		len_word = size_word(s, c) + 1;
		if (!(answer[i] = (char*)malloc(sizeof(**answer) * len_word)))
		{
			ft_free(&answer, i);
			return (NULL);
		}
		ft_make_str(&s, c, answer[i]);
		++i;
	}
	answer[i] = NULL;
	return (answer);
}
