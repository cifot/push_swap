/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:50:33 by nharra            #+#    #+#             */
/*   Updated: 2019/10/04 12:50:48 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

typedef struct	s_count
{
	int		a;
	int		b;
}				t_count;

void			push_swap_output_ra(t_stack *a, t_stack *b, int n);

void			push_swap_output_rb(t_stack *a, t_stack *b, int n);

void			check_is_sorted_first_a(t_stack *a, int *n);
void			check_is_sorted_first_b(t_stack *a, t_stack *b, int *n);

void			last_1a1b(t_stack *a, t_stack *b);
void			last_2a1b(t_stack *a, t_stack *b);
void			last_1a2b(t_stack *a, t_stack *b);
void			last_2a2b(t_stack *a, t_stack *b);

void			last_1b(t_stack *a, t_stack *b);
void			last_2b(t_stack *a, t_stack *b);
void			last_3b(t_stack *a, t_stack *b);

void			last_1a(t_stack *a, t_stack *b);
void			last_2a(t_stack *a, t_stack *b);
void			last_3a(t_stack *a, t_stack *b);

#endif
