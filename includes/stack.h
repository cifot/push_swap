/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:27:57 by nharra            #+#    #+#             */
/*   Updated: 2019/10/16 00:19:27 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

#include "libft.h"

int			make_input(int argc, char **argv, t_stack *stack);
void		push_op(t_stack *from, t_stack *to);
void		rotate_op(t_stack *stack);
void		rev_rotate_op(t_stack *stack);
void		swap_op(t_stack *stack);
int			check_swap(t_stack *a, t_stack *b, char *line);
int			check_push(t_stack *a, t_stack *b, char *line);
int			check_rot(t_stack *a, t_stack *b, char *line);

#endif
