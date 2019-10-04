/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 20:28:03 by nharra            #+#    #+#             */
/*   Updated: 2019/10/04 20:31:02 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

long			ft_atol(const char *str)
{
	long		unswer;
	int			flag;
	int			i;

	i = 0;
	flag = 1;
	unswer = 0;
	while (ft_is_space(str[i]))
	{
		++i;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		++i;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		unswer = unswer * 10 + flag * (str[i] - '0');
		++i;
	}
	return (unswer);
}
