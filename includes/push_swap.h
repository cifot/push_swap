/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:44:30 by nharra            #+#    #+#             */
/*   Updated: 2019/10/02 15:44:39 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef enum	e_op {
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}				t_op;

# include "utilities.h"

int			check_same(t_dlist **st_a, t_dlist **st_b);
int			find_middle(const t_dlist *beg, const t_dlist *end);
size_t		ft_dlist_len(t_dlist *beg, t_dlist *end);

#endif
